#include <unordered_map>
#include <hash.h>
#include <cacheline.h>


Hash::Hash(int c, int b, int a, int addr){

    counter = 0;

    cache_size = c;
    block_size = b;


    if(a==0){
        num_set = 1;
        associativity = cache_size/block_size;
    }else{
        associativity = a;
        num_set = (cache_size/block_size)/associativity;
    }

    for(int i=0;i<num_set;i++){
        hashmap[i] = std::vector<Cacheline>(associativity);
    }

    o = std::log2(block_size);
    i = std::log2(num_set);
    t = addr - i - o;

    //print widths
    std::cout << "Offset: " << o << " bits" << std::endl;
    std::cout << "Index: " << i << " bits" << std::endl;
    std::cout << "Tag: " << t << " bits" << std::endl;
    std::cout << "Number of Lines: " << num_set << std::endl;
}

int Hash::tag(){
    return t;
}

int Hash::index(){
    return i;
}

int Hash::offset(){
    return o;
}

int Hash::num_sets(){
    return num_set;
}

int Cache::get_counter(){
    return counter;
}

