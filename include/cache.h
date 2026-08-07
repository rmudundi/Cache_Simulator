#pragma once

Class Cache{
    int cache_size;
    int block_size;
    int num_set;
    int associativity;
    int o;
    int i;
    int t;

    std::vector<Cacheset> table;

    public: 
        Cache(int c_size, int b_size, int a, int addr);

        search_cache(long int tag, long int index);

        int offset() const;

        int index() const;

        int tag() const;

        int num_sets() const;
        

};