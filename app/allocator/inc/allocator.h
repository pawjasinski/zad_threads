#ifndef ALLOCATOR_H
#define ALLOCATOR_H
#include <memory>
#include <mutex>
#include <condition_variable>
#include <iostream>

class Allocator
{
public:
    Allocator() = default;

    std::shared_ptr<char> wait_get_buffer(int nmb)
    {
        std::unique_lock<std::mutex> lck{mtx_};
        size_buffer_ = num_digits(nmb) + 1;
        std::cout << "Allocator size_buffer = " << size_buffer_ << "\n";
        cv_.notify_one();
        while(buffer_ == nullptr)
        {
            cv_.wait(lck);
        }
        return std::move(buffer_);
    }

    std::shared_ptr<char> try_get_buffer(int nmb)
    {
        std::unique_lock<std::mutex> lck{mtx_, std::defer_lock};
        if(lck.try_lock())
        {
        }
        else
        {
            return std::shared_ptr<char>{nullptr};
        }
    }

    void set_buffer()
    {
        std::unique_lock<std::mutex> lck{mtx_};
        while(size_buffer_ == 0)
        {
            cv_.wait(lck);
        }
        buffer_ = std::shared_ptr<char>(new char[size_buffer_], std::default_delete<char[]>() );
        size_buffer_ = 0;
        cv_.notify_one();
    }

    void run()
    {
        while (true)
        {
            std::cout << "Allocator run()\n";
            set_buffer();
        }
    }

protected:
    std::mutex mtx_;
    std::condition_variable cv_;
    std::shared_ptr<char> buffer_{nullptr};
    size_t size_buffer_{0};

    int num_digits(int num)
    {
        int ret = 0;
        if(num < 10 && num > -10)
        {
            ret = 1;
            return ret;
        }
        while(num)
        {
            num /= 10;
            ++ret;
        }
        return ret;
    }
};

#endif // ALLOCATOR_H
