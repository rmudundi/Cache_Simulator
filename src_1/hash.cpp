#include <unordered_map>
#include <hash.h>
#include <cacheline.h>
#include <cmath>
#include <iostream>
#include <climits>

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



    o = std::log2(block_size);
    i = std::log2(num_set);
    t = addr - i - o;
}

//returns if its a hit or miss, returns m to determine what type of miss
int Hash::search(int idx, int t, int& m){ //miss = 0, hit = 1
    counter++;
    int check = 0;
    if(!hashmap[idx].empty()){
        //could be a miss or hit
        for(int i=0;i<associativity;i++){

            if(hashmap[idx][i].get_tag() != t){
                check++;
            }

            if(hashmap[idx][i].get_tag() == t && hashmap[idx][i].get_valid()== 1 ){
                std::cout << "HIT" << std::endl;
                return 1;
            }
        }

        if(check==associativity){
            //miss but full
            m = 1;
            return 0;
        }

    }else{
        //miss when empty
        m = 0;
        std::cout << "MISS" << std::endl;
        Cacheline obj;
        counter += 4;
        obj.set_valid(1);
        obj.set_tag(t);
        obj.set_LRU(counter);
        hashmap[idx].resize(associativity);
        hashmap[idx][0] = obj; //might not work
        return 0;
    }
    
    return 0;
}

//takes care of misses when full

void Hash::evict(int id, int t){
    counter+=4;
    int low = INT_MAX;
    int save = 0;
    for(int i=0;i<associativity;i++){
        if (hashmap[id][i].get_LRU() < low){
            low = hashmap[id][i].get_LRU();
            save = i;
        }
    }
    hashmap[id][save].set_tag(t);
    hashmap[id][save].set_LRU(counter);
    hashmap[id][save].set_valid(1);

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

