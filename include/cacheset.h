#ifndef CACHESET_H
#define CACHESET_H
#include <iostream>
#include <cacheline.h>


class Cacheset{

    std::vector<Cacheline> lines;

    public: 
        Cacheset(int a);

        bool check(long int tag,long int counter);
    
};

#endif