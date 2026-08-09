#include <iostream>
#include <cacheline.h>
#include <cache.h>

//constructor
Cacheset::Cacheset(int a){
    lines.emplace_back();
}

bool Cacheset::check(long int tag, long int counter){

    //table comes from Cache Class
    for(int i=0;i<lines.size();i++){
        if(lines[i].get_tag() == tag && lines[i].get_valid() == 1){ //hit and LRU updated
            lines[i].set_LRU(counter);
            return 1;
        }
    }
    return 0; //miss 
}
