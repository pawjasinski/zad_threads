#include<iostream>
#include "random_engine.h"


int main(int argc, char** argv)
{
    std::cout << "Hello world" << std:: endl;
    pawelo::RandomEngine<double> rr(5.0, 10.0);
    pawelo::RandomEngine<int> rrr(5.0, 10.0);
    std::cout << rr() << "|" << rr() << "|" << rr() << "|" << rr() << "|" << std::endl;
    std::cout << rrr() << "|" << rrr() << "|" << rrr() << "|" << rrr() << "|" << std::endl;
    return EXIT_SUCCESS;
}