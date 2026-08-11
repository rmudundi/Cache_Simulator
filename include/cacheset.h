#ifndef CACHESET_H
#define CACHESET_H
#include <iostream>
#include <cacheline.h>
#include <vector>


class Cacheset{

    std::vector<Cacheline> lines;
    int size;

    public: 
        Cacheset(int a);

        void enter_entry(long int tag, long int counter);

        bool check(long int tag,long int counter);

        int get_size();

    
};

#endif