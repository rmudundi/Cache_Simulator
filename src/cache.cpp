#include <iostream>
#include <cmath>
#include <vector>
#include <cacheset.h>


class Cache{

    int cache_size;
    int block_size;
    int num_set;
    int associativity;

    std::vector<Cacheset> table;

    public: 

        Cache(int c_size, int b_size, int a) {
            
            //assign variables
            cache_size = c_size;
            block_size = b_size;
            associativity = a;
            

            //find num of sets
            num_set = (cache_size/block_size)/associativity;
            
            //make cache
            table.resize(num_set)

            //handle errors later
            
        }
    
    }
};
//function to initilize a cache diagram

//decode the address
//Number of sets = cache size / block size
//Offset bits = log2(block size)
//index bits = log2number of sets
//tag = whats left

//ex of TIO = 20,8,4
//can shift by bits and & by 0xF or 0xFF

//search by index in cache

//call specific set->cacheset

//if empty and bit = N, miss, put tag into line
//if same index, filled, replace

