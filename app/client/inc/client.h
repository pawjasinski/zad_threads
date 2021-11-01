#ifndef CLIENT_H
#define CLIENT_H
#include <cassert>
#include "random_engine.h"
#include <limits>
#include "queue_sync.h"
#include <vector>
#include <chrono>
#include <thread>
#include <fstream>
#include <iostream>



class Client
{
public:
    Client(int id, pawelo::QueueSynch<int>* queue) : re(0, INT32_MAX), queue_synch_(queue), id_(id)
    {
        assert(queue != nullptr);
    }
    ~Client()
    {
        std::fstream fout;
        char buff[100];
        sprintf(buff, "Client id: %i", id_);
        fout.open(buff,std::ios::out);
        if(fout.is_open())
        {
            for (auto i: cont_int_)
            {
                fout << i << std::endl;
            }
        }
        else
        {
            std::cerr << "Something went wrong with write to file Client id: " << id_ << std::endl;
        }
    }
    void run()
    {
        while(true)
        {
            std::cout << "Run Client\n";
            int tmp = gen_rand();
            queue_synch_->push(tmp);
            cont_int_.push_back(tmp);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
    int gen_rand()
    {
        return re();
    }
    void setQueue(pawelo::QueueSynch<int>* queue)
    {
        assert(queue != nullptr);
        queue_synch_ = queue;
    }
protected:
    int id_;
    pawelo::RandomEngine<int> re;
    std::vector<int> cont_int_;
    pawelo::QueueSynch<int>* queue_synch_;
};

#endif // CLIENT_H