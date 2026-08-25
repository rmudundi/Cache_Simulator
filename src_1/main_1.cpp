// #include <iostream>
// #include <fstream>
// #include <string>
// #include <chrono>
// #include <stats.h>
// #include <hash.h>

// int main(){

//     int cache_size;
//     int block_size;
//     int address;
//     int associativity;
//     int t_bit;
//     int i_bit;
//     long int tg;
//     long int idx;

//     std::cout << "Hash-Based Cache Simulator:" << std::endl;
//     std::cout << "Enter Cache Size(KB):" << std::endl;
//     std::cin >> cache_size;
//     std::cout << "Enter Block Size(Bytes):" << std::endl;
//     std::cin >> block_size;
//     std::cout << "Enter Address Size(bits):" << std::endl;
//     std::cin >> address;
//     std::cout << "Enter Associativity:( Direct[1] , Set[#] , Full[0] )" << std::endl;
//     std::cin >> associativity;

//     //makes cache vector
//     cache_size *= 1024;

//     std::cout << "Opening File...." << std::endl;
//     std::ifstream f("trace/sample.trace"); //might need to change to variable when testing multiple files
//     std::string ad;

//     if(!f.is_open()){
//         std::cout << "Failed to open file!" << std::endl;
//     }

//     auto start = std::chrono::high_resolution_clock::now();

//     while(std::getline(f,ad)){
//         std::cout << "Processing: " << ad << std::endl;
//         myStats.count_inst();

//         //converted to hex
//         long int hex_addr = std::stoul(ad,nullptr,16);

//         hex_addr = hex_addr >> HashMap.offset(); //removes the offset digits
            
//         //example, idx = 2 bits so 100, 100 - 1, 011 = bit mask of 2 1's
//         idx = ((1<<i_bit)-1) & hex_addr;
//         hex_addr = hex_addr >> i_bit;
//         tg = hex_addr;

//         //logic for hit and miss
//         if(HashMap.search(idx,tg)){
//             std::cout << "MISS" << std::endl;
//             HashMap.evict(idx,tg);
//         }
            
//     }

//     auto end = std::chrono::high_resolution_clock::now();
//     auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);

//     std::cout << std::endl;
//     myStats.set_cycles(HashMap.get_counter());
//     myStats.set_clocktime(duration.count());
//     myStats.rates();
//     std::cout << "TRACE FILE COMPLETE" << std::endl;

//     //print results
//     myStats.print_results();

// }