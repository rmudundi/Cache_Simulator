#include <iostream>
#include <cmath>
#include <vector>
#include <cacheset.h>
#include <cache.h>



Cache::Cache(int c_size, int b_size, int a, int addr) {
            
    //assign variables
    cache_size = c_size;
    block_size = b_size;

    //find num of sets/lines
    if(a==0){
        num_set = 1;
    }else{
        associativity = a;
        num_set = (cache_size/block_size)/associativity;

    }

    //make cache
    table.resize(num_set);
    for(int i=0;i<table.size();i++){
        table[i] = Cacheset(associativity);
    }

    o = std::log2(block_size);
    i = std::log2(num_set);
    t = addr - i - o;

    //print widths
    std::cout << "Offset: " << o << "bits" << std::endl;
    std::cout << "Index: " << i << "bits" << std::endl;
    std::cout << "Tag: " << t << "bits" << std::endl;
    std::cout << "Number of Lines: " << num_set << std::endl;

    //handle errors later
            
}

bool Cache::search_cache(long int tag, long int index){
    return table[index].check(tag);
}

int Cache::tag() const{
    return t;
}

int Cache::index() const{
    return i;
}

int Cache::offset() const{
    return o;
}

int Cache::num_sets() const{
    return num_set;
}


    
