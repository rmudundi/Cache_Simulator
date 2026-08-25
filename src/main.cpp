#include <iostream>
#include <cache.h>
#include <fstream>
#include <string>
#include <cmath>
#include <stats.h>
#include <chrono>
#include <hash.h>

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
    

    std::cout << "Vector-Based Cache Simulator:" << std::endl;
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
    Stats vector_stats;

    //makes cache hash
    Hash HashMap(cache_size,block_size,associativity,address);
    Stats hash_stats;
    
    //open the file
    std::cout << "Opening File..." << std::endl;
    std::ifstream f("trace/sample.trace");
    std::string ad;

    //file error handling
    if(!f.is_open()){
        std::cout << "Failed to open file!" << std::endl;
    }

    auto start = std::chrono::high_resolution_clock::now();

    while(std::getline(f,ad)){
        std::cout << "Processing:" << ad << std::endl; //0x12345 67 8
        vector_stats.count_inst();

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
            vector_stats.update_hit();
            
        }else{
            std::cout << "MISS" << std::endl;
            myCache.evict(tg,idx);
            vector_stats.update_miss();
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);

    std::cout << std::endl;
    vector_stats.set_cycles(myCache.get_counter());
    vector_stats.set_clocktime(duration.count());
    vector_stats.rates();
    std::cout << "TRACE FILE COMPLETE FOR Vector Cache" << std::endl;

    f.close(); 

    std::cout << "Opening File ...." << std::endl;
    std::ifstream ff("trace/sample.trace"); //might need to turn to a variable
    std::string ad1;

    if(!ff.is_open()){
        std::cout << "Failed to open file!" << std::endl;
    }

    auto start1 = std::chrono::high_resolution_clock::now();

    while(std::getline(ff,ad1)){
        std::cout << "Processing: " << ad1 << std::endl;
        hash_stats.count_inst();

        //converted to hex
        long int hex_addr = std::stoul(ad1,nullptr,16);

        hex_addr = hex_addr >> HashMap.offset(); //removes the offset digits
            
        //example, idx = 2 bits so 100, 100 - 1, 011 = bit mask of 2 1's
        idx = ((1<<i_bit)-1) & hex_addr;
        hex_addr = hex_addr >> i_bit;
        tg = hex_addr;

        //logic for hit and miss
        bool temp = 0;
        
        int m;
        if(!HashMap.search(idx,tg,m)){
            //miss

            //miss when empty = 0
            if(!m){
                std::cout << "MISS" << std::endl;
                hash_stats.update_miss();
                //temp = 1;
            }else{
                //miss when full = 1
                std::cout << "MISS" << std::endl;
                hash_stats.update_miss();
                HashMap.evict(idx,tg);
                //temp = 1;
            }
            
        }
        else{
            //hit
            std::cout << "HIT: " << ad1 << "already in Cache" << std::endl;
            hash_stats.update_hit();
            
        }

        
    }

    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1-start1);

    std::cout << std::endl;
    hash_stats.set_cycles(HashMap.get_counter());
    hash_stats.set_clocktime(duration1.count());
    hash_stats.rates();
    std::cout << "TRACE FILE COMPLETE for Hash Cache" << std::endl;

    ff.close();

    //print stats
    Stats final_stats;

    final_stats.results(vector_stats, hash_stats);
}