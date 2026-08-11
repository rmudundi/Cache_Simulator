#include <iostream>
#include <cmath>
#include <vector>
#include <cacheset.h>
#include <cache.h>
#include <climits>


Cache::Cache(int c_size, int b_size, int a, int addr) {
           
    counter = 0;

    //assign variables
    cache_size = c_size;
    block_size = b_size;

    //find num of sets/lines
    if(a==0){
        num_set = 1;
        associativity = cache_size/block_size;
    }else{
        associativity = a;
        num_set = (cache_size/block_size)/associativity;

    }

    //make cache
    for(int i=0;i<num_set;i++){
        table.emplace_back(associativity);   
    }

    o = std::log2(block_size);
    i = std::log2(num_set);
    t = addr - i - o;

    //print widths
    std::cout << "Offset: " << o << " bits" << std::endl;
    std::cout << "Index: " << i << " bits" << std::endl;
    std::cout << "Tag: " << t << " bits" << std::endl;
    std::cout << "Number of Lines: " << num_set << std::endl;

    //handle errors later
            
}

bool Cache::search_cache(long int tag, long int index){
    counter++;
    return table[index].check(tag,counter);
}

void Cache::evict(long int tag, long int index){
    //set new tag in index
    counter += 4;
    table[index].enter_entry(tag, counter);
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


    
