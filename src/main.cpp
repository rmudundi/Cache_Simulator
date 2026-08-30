#include <iostream>
#include <cache.h>
#include <fstream>
#include <string>
#include <cmath>
#include <stats.h>
#include <chrono>
#include <hash.h>

double test_vector(int associativity, int cache_size, int block_size, int address){

    std::vector<long long> time_avg;
    int a = 0;
    cache_size *= 1024;

    while(a < 10){ 

        int i_bit;
        int t_bit;
        int tg;
        int idx;

        //makes cache vector
        
        Cache myCache(cache_size,block_size,associativity,address);
        Stats vector_stats;

        //open the file
        //std::cout << "Opening File..." << std::endl;
        std::ifstream f("trace/sample.trace");
        std::string ad;


        //file error handling
        if(!f.is_open()){
            std::cout << "Failed to open file!" << std::endl;
        }

        auto start = std::chrono::high_resolution_clock::now();

        while(std::getline(f,ad)){
            
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
            //std::cout << "IDX: " << idx << std::endl;
            hex_addr = hex_addr >> i_bit;
            tg = hex_addr;

        
            //check in myCache for entry
            if(myCache.search_cache(tg, idx) == 1){
               
                vector_stats.update_hit();
                
            }else{
                
                myCache.evict(tg,idx);
                vector_stats.update_miss();
            }
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);

        
        vector_stats.set_cycles(myCache.get_counter());
        vector_stats.set_clocktime(duration.count());
        vector_stats.rates();
       

        f.close(); 
        a++;
        time_avg.push_back(duration.count());

    }

    long long int sum = 0;
    for(long long int s : time_avg){
        sum += s;
    }
    double avg = sum/time_avg.size();

    return avg;
}



double test_hash(int associativity, int cache_size, int block_size, int address){

    std::vector<long long> time_avg;
    int a = 0;
    cache_size *= 1024;

    while(a<10){

        
        int i_bit;
        int t_bit;
        int tg;
        int idx;
        
        //makes cache hash
        Hash HashMap(cache_size,block_size,associativity,address);
        Stats hash_stats;
        
    

        //repeat again with new filestream for hash map
        std::ifstream ff("trace/sample.trace"); //might need to turn to a variable
        std::string ad1;

        if(!ff.is_open()){
            std::cout << "Failed to open file!" << std::endl;
        }

        auto start1 = std::chrono::high_resolution_clock::now();

        while(std::getline(ff,ad1)){
           
            hash_stats.count_inst();

            //converted to hex
            long int hex_addr = std::stoul(ad1,nullptr,16);

            hex_addr = hex_addr >> HashMap.offset(); //removes the offset digits
                
            //example, idx = 2 bits so 100, 100 - 1, 011 = bit mask of 2 1's
            idx = ((1<<i_bit)-1) & hex_addr;
            hex_addr = hex_addr >> i_bit;
            tg = hex_addr;

            //logic for hit and miss
            int m; //passed by ref
            if(!HashMap.search(idx,tg,m)){
                //miss

                //miss when empty = 0
                if(!m){
                   
                    hash_stats.update_miss();

                }else{

                    //miss when full = 1
                    hash_stats.update_miss();
                    HashMap.evict(idx,tg);
                }
                
            }
            else{
                //hit
                hash_stats.update_hit();
                
            }

            
        }

        auto end1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1-start1);

        
        hash_stats.set_cycles(HashMap.get_counter());
        hash_stats.set_clocktime(duration1.count());
        hash_stats.rates();
        

        ff.close();
        a++;
        time_avg.push_back(duration1.count());

    }

    
    int sum = 0;
    for(auto s : time_avg){
        sum += s;
    }

    double avg = sum/time_avg.size();

    return avg;

}



int main(){
    //testing 32 bit address, 4KB cache size, and 16 byte blocks
    int cache_size;
    int block_size;
    int address;
   
    

    std::cout << "Cache Simulator:" << std::endl;
    std::cout << "Enter Cache Size(KB):" << std::endl;
    std::cin >> cache_size;
    std::cout << "Enter Block Size(Bytes):" << std::endl;
    std::cin >> block_size;
    std::cout << "Enter Address Size(bits):" << std::endl;
    std::cin >> address;
  

    std::vector<int> num = {1,2,4,8,16,0};

    for(int x=0;x<num.size();x++){



        double t1 = test_vector(num[x], cache_size, block_size, address);
        double t2 = test_hash(num[x], cache_size, block_size, address);

        if(x==0){
            //direct stats;
            std::cout << "=============================" << std::endl;
            std::cout << "     Direct Mapping Stats    " << std::endl;
            std::cout << "-----------------------------" << std::endl;
            std::cout << "   Vector     |      Hash    " << std::endl; 
            std::cout << "     " << t1 << " us           " << t2 << " us"  << std::endl;
           
            std::cout << "======================================" << std::endl;
            std::cout << "             Set-Associative Stats   " << std::endl;
            std::cout << "--------------------------------------" << std::endl;
            std::cout << "              Vector    |      Hash    " << std::endl; 
        }else if(x==5){
            std::cout << "=============================" << std::endl;
            std::cout << "   Fully-Associative Stats   " << std::endl;
            std::cout << "-----------------------------" << std::endl;
            std::cout << "     Vector     |      Hash    " << std::endl; 
            std::cout << "     " << t1 << " us           " << t2 << " us"  << std::endl;
        }else{
          
            std::cout << "Set of "  << num[x] << " :      " << t1 << " us           " << t2 << " us"  << std::endl;
        }
        
       
    }


    
}