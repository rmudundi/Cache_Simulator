#include <iostream>
#include <cache.h>
#include <fstream>
#include <string>
#include <cmath>

int main(){
    //testing 32 bit address, 4KB cache size, and 16 byte blocks, direct

    int cache_size;
    int block_size;
    int address;
    int associativity;
    int t_bit;
    int i_bit;
    long int tg;
    long int idx;
    

    std::cout << "Cache Simulator:" << std::endl;
    std::cout << "Enter Cache Size(KB):" << std::endl;
    std::cin >> cache_size;
    std::cout << "Enter Block Size(Bytes):" << std::endl;
    std::cin >> block_size;
    std::cout << "Enter Address Size(bits):" << std::endl;
    std::cin >> address;
    std::cout << "Enter Associativity:( Direct[1] , Set[#] , Full[0] )" << std::endl;
    std::cin >> associativity;

    //makes cache vector
    cache_size *= 1024;
    Cache myCache(cache_size,block_size,associativity,address);
    

    std::ifstream f("../trace/sample.trace");
    
    std::string ad;

    while(std::getline(f,ad)){
        std::cout << "Processing:" << ad << std::endl; //0x12345 67 8
        
        //converted to hex
        long int hex_addr = std::stoul(ad,nullptr,16); 

        //retirves bit size functions from Cache class
        t_bit = myCache.tag();
        i_bit = myCache.index();

        //shift addr by offset bits
        hex_addr = hex_addr >> myCache.offset();
        //(1<<i_bit) makes the mask of 1's
        idx = ((1 << i_bit)-1) & hex_addr; 
        hex_addr = hex_addr >> i_bit;
        tg = hex_addr;

        
        //check in myCache for entry
        if(myCache.search_cache(tg, idx) == 1){
            std::cout << "HIT: " + ad + " already in Cache" << std::endl;
        }else{
            myCache.evict(tg,idx);
        }
    }


    //print stats or put stats into a folder



}