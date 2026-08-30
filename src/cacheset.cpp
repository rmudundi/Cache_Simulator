#include <iostream>
#include <cacheline.h>
#include <cache.h>
#include <climits>

//constructor
Cacheset::Cacheset(int a){
    size = a;
    for(int i=0;i<a;i++){
        lines.emplace_back();
    }
} 

void Cacheset::enter_entry(long int tag,long int counter){
    int full = 1;
    //std::cout << "M" << " " << tag << " "  << counter << std::endl;
    for(int i = 0;i<lines.size();i++){
        if(lines[i].get_valid() == 0){
            //empty slot to fill
            full = 0;
            lines[i].set_tag(tag);
            lines[i].set_LRU(counter);
            lines[i].set_valid(1);
            break;
        }
    }

    if(full==1){
        //find lowest LRU and change the tag for that;
        int low = INT_MAX; 
        int save = 0;
        for(int i = 0;i<lines.size();i++){
            if (lines[i].get_LRU() < low) {
                low = lines[i].get_LRU();
                save = i;
            }
        }
        //std::cout << "SAVE: " << save << std::endl;
        //std::cout << "Prev tag: " << lines[save].get_tag() << std::endl;
        lines[save].set_LRU(counter);
        lines[save].set_tag(tag);
        lines[save].set_valid(1);
        //std::cout << "New tag: " << lines[save].get_tag() << std::endl;
    }
}


bool Cacheset::check(long int tag, long int counter){

    //table comes from Cache Class
    for(int i=0;i<lines.size();i++){
        if(lines[i].get_tag() == tag && lines[i].get_valid() == 1){ //hit and LRU updated
            lines[i].set_LRU(counter);
            //std::cout << "H: " << tag << " " << counter << std::endl;
            return 1;
        }
    }
    return 0; //miss 
}

int Cacheset::get_size(){
    return size;
}
