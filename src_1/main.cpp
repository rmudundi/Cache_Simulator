#include <iostream>
#include <fstream>
#include <string>


int main(){

    std::cout << "Hash Based Cache Simulator:" << std::endl;
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
    Hash myHash(cache_size,block_size,associativity,address);
    Stats myStats;


}