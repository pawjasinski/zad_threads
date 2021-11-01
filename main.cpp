#include<iostream>
#include <thread>
#include "thread_pool.h"
#include "random_engine.h"
#include "queue_sync.h"
#include "allocator.h"
#include "client.h"
#include "server.h"
#include "watchdog.h"

const int clientThreads = 5;
const int serverThreads = 3;
const int allocatorThreads = 2;
const int watchdogThread = 1;


int main(int argc, char** argv)
{
    std::cout << "Hello world zadanie" << std:: endl;
    pawelo::ThreadPool clients(clientThreads);
    pawelo::ThreadPool servers(serverThreads);
    pawelo::ThreadPool allocators(allocatorThreads);
    pawelo::ThreadPool watchdog(watchdogThread);
    //std::shared_ptr<pawelo::QueueSynch<int>> que_s = std::make_shared<pawelo::QueueSynch<int>>();
    pawelo::QueueSynch<int>* que_s = new pawelo::QueueSynch<int>();
    Server srv1(que_s);
    Server srv2(que_s);
    Server srv3(que_s);

    Client cl1(1, que_s);
    Client cl2(2, que_s);
    Client cl3(3, que_s);
    Client cl4(4, que_s);
    Client cl5(5, que_s);

    Allocator alloc1;
    Allocator alloc2;

    srv1.set_alloc_mem(&alloc1);
    srv2.set_alloc_mem(&alloc1);
    srv3.set_alloc_mem(&alloc2);

    servers.submit([&srv1]{srv1.run();});
    servers.submit([&srv2]{srv2.run();});
    servers.submit([&srv3]{srv3.run();});

    clients.submit([&cl1]{cl1.run();});
    clients.submit([&cl2]{cl2.run();});
    clients.submit([&cl3]{cl3.run();});
    clients.submit([&cl4]{cl4.run();});
    clients.submit([&cl5]{cl5.run();});

    allocators.submit([&alloc1]{alloc1.run();});
    allocators.submit([&alloc2]{alloc2.run();});

    return EXIT_SUCCESS;
}