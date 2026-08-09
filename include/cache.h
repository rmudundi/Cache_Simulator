#ifndef CACHE_H
#define CACHE_H
#include <vector>
#include <cacheset.h>

class Cache{
    int cache_size;
    int block_size;
    int num_set;
    int associativity;
    int o;
    int i;
    int t;

    long int counter;

    std::vector<Cacheset> table;

    public: 
        Cache(int c_size, int b_size, int a, int addr);

        bool search_cache(long int tag, long int index);

        void evict(long int tag, long int index);

        int offset() const;

        int index() const;

        int tag() const;

        int num_sets() const;
        

};


#endif