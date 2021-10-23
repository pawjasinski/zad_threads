#ifndef QUEUE_SYNCH_H
#define QUEUE_SYNCH_H
#include <queue>
#include <mutex>
#include <condition_variable>
#include <initializer_list>
#include <chrono>

namespace pawelo
{
    template<class T>
    class QueueSynch
    {
    public:
        QueueSynch() = default;
        ~QueueSynch() = default;
        QueueSynch(const QueueSynch&) = default;
        QueueSynch& operator=(const QueueSynch&) = default;
        void push(const T& item)
        {
            std::lock_guard<std::mutex> lck{lock_};
            list_.push(item);
            is_not_empty_.notify_one();
        }
        void push(T&& item)
        {
            std::lock_guard<std::mutex> lck{lock_};
            list_.push(std::move(item));
            is_not_empty_.notify_one();
        }
        void push(std::initializer_list<T> list)
        {
            {
                std::lock_guard<std::mutex> lck{lock_};
                for(const auto& i : list)
                {
                    list_.push(i);
                }
            }
            is_not_empty_.notify_all();
        }
        void pop(T& item)
        {
            std::unique_lock<std::mutex> lck{lock_};
            //while(list_.empty())
            //{
            //    is_not_empty_.wait(lck);
            //}
            is_not_empty_.wait(lck, [this] {return !list_.empty();});
            item = std::move(list_.front());
            list_.pop();
        }
        bool try_pop(T& item, std::chrono::milliseconds delay = 100ms)
        {
            std::unique_lock<std::mutex> lck(lock_, std::defer_lock);
            lck.try_lock_for(delay);
            if(!lck.owns_lock() || list_.empty())
            {
                return false;
            }
            item = std::move(list_.front());
            list_.pop();
            return true;
        }
    protected:
        std::queue<T> list_;
        std::mutex lock_;
        std::condition_variable is_not_empty_;
    };
}

#endif // QUEUE_SYNCH_H