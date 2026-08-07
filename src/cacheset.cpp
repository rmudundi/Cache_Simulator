#include <iostream>
#include <cacheline.h>
#include <cache.h>

//constructor
Cacheset::Cacheset(int a){
    lines.resize(a);
}

bool Cacheset::check(long int tag){
    //table comes from Cache Class
    for(int i=0;i<lines.size();i++){
        if(lines[i]==tag){
            return 1;
        }
    }
    return 0;  
}
