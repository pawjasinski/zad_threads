#ifndef SERVER_H
#define SERVER_H
#include <cassert>
#include <iostream>
#include <thread>
#include <chrono>
#include <memory>
#include "queue_sync.h"
#include "allocator.h"
#include <stdio.h>
#include <string.h>

class Server
{
public:
    Server(pawelo::QueueSynch<int>* queue) : queue_synch_client(queue)
    {
        assert(queue != nullptr);
    }

    void set_alloc_mem(Allocator* alloc)
    {
        assert(alloc != nullptr);
        alloc_mem = alloc;
    }

    void run()
    {
        while(true)
        {
            int rnd;
            queue_synch_client->pop(rnd);
            std::cout << "Run Server get from client: " << rnd << "\n";
            std::shared_ptr<char> ptr = alloc_mem->wait_get_buffer(rnd);
            sprintf(ptr.get(), "%i", rnd);
            std::cout << "Po dostaniu bufora: " << ptr << "\n";

        }
    }
    void set_client_queue(pawelo::QueueSynch<int>* queue)
    {
        assert(queue != nullptr);
        queue_synch_client = queue;
    }
protected:
    pawelo::QueueSynch<int>* queue_synch_client;
    Allocator* alloc_mem;
};

#endif // SERVER_H