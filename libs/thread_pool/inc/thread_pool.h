#ifndef THREAD_POOL_H
#define THREAD_POOL_H
#include <vector>
#include <functional>
#include <thread>
#include <future>
#include <mutex>
#include "queue_sync.h"
namespace pawelo
{
    using Task = std::function<void()>;
    class ThreadPool
    {
    public:
        ThreadPool(size_t num_of_threads):threads_(num_of_threads), is_ready(true)
        {
            for(int i = 0; i < threads_.size(); ++i)
            {
                threads_[i] = std::thread([this]{ run(); });
            }
        }
        ~ThreadPool()
        {
            for(int i = 0; i < threads_.size(); ++i)
            {
                submit([this]{ is_ready = false; });
            }
            for(auto& i : threads_)
            {
                i.join();
            }
        }
        ThreadPool(const ThreadPool&) = delete;
        ThreadPool& operator=(const ThreadPool&) = delete;

        template<class Callable>
        void submit(Callable&& callable)
        {
            using result = decltype(callable());
            //std::packaged_task<std::shared_ptr<result()>> p = std::make_shared<result()>(std::forward<Callable>(callable));
            auto pt = std::make_shared<std::packaged_task<result()>>(std::forward<Callable>(callable));
            tasks_.push([pt] {(*pt)();});
        }
        void run()
        {
            while(true)
            {
                Task task;
                tasks_.pop(task);
                task();
                if(!is_ready)
                    return;
            }
        }
    protected:
        QueueSynch<Task> tasks_;
        std::vector<std::thread> threads_;
        std::atomic<bool> is_ready;
    };
}

#endif // THREAD_POOL_H