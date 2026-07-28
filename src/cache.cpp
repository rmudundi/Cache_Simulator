#include <iostream>
#include <cmath>
#include <vector>
#include <cacheset.h>
#include <cache.h>



Cache::Cache(int c_size, int b_size, int a) {
            
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

