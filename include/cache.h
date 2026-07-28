#pragma once

Class Cache{
    int cache_size;
    int block_size;
    int num_set;
    int associativity;

    std::vector<Cacheset> table;

    public: 
        Cache(int c_size, int b_size, int a);

};