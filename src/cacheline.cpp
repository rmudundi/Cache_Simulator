#include <cacheline.h>

Cacheline::Cacheline(){
    tag = 0;
    valid = 0;
    LRU = 0;
}

void Cacheline::set_tag(long int t){
    tag = t;
}

void Cacheline::set_valid(bool v){
    valid = v;
}


void Cacheline::set_LRU(long int time){
   LRU = time;
}

long int Cacheline::get_tag(){
    return tag;
}

bool Cacheline::get_valid(){
    return valid;
}

int Cacheline::get_LRU(){
    return LRU;
}
