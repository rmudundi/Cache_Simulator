#include <unordered_map>
#include <hash.h>
#include <cacheline.h>
#include <cmath>
#include <iostream>



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

    // for(int i=0;i<num_set;i++){
    //     hashmap[i] = std::vector<Cacheline>(associativity);
    // }

    o = std::log2(block_size);
    i = std::log2(num_set);
    t = addr - i - o;

    //print widths
    std::cout << "Offset: " << o << " bits" << std::endl;
    std::cout << "Index: " << i << " bits" << std::endl;
    std::cout << "Tag: " << t << " bits" << std::endl;
    std::cout << "Number of Lines: " << num_set << std::endl;
}

//inserts in miss if empty, hit, but not miss if full 
bool Hash::search(int idx, int t){ //miss = 0, hit = 1
    counter++;
    int check = 0;
    if(!hashmap[idx].empty()){
        //could be a miss or hit
        for(int i=0;i<associativity;i++){

            if(hashmap[idx][i].get_tag() != t){
                check++;
            }

            if(hashmap[idx][i].get_tag() == t && hashmap[idx][i].get_valid()== 1 ){
                return 1;
            }
        }

        if(check==associativity){
            //miss but full
            return 1;
        }

    }else{
        //miss
        Cacheline obj;
        counter += 4;
        obj.set_valid(1);
        obj.set_tag(t);
        //obj.set_index(idx);
        obj.set_LRU(counter);
        hashmap[idx][0] = obj; //might not work
        return 0;
    }
    return 0;
}

//takes care of misses when full, 
void evict(int i, int t){

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

int Hash::get_counter(){
    return counter;
}

