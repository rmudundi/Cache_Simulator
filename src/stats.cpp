#include <iostream>
#include <vector>
#include <stats.h>

Stats::Stats(){
    instructions = 0;
    hit = 0.0;
    miss = 0.0;
    hit_rate = 0.0;
    miss_rate = 0.0;
    cycles = 0;
}

void Stats::update_hit(){
    hit++;
}

void Stats::update_miss(){
    miss++;
}

void Stats::count_inst(){
    instructions++;
}

void Stats::set_cycles(long int counter){
    cycles = counter;
}

void Stats::rates(){
    //std::cout << hit << std::endl;
    //std::cout << miss << std::endl;
    hit_rate = hit/instructions * 100;
    miss_rate = miss/instructions * 100;
}

void Stats::print_results(){
    std::cout << "Stats:" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Total # of Instructions: " << instructions << std::endl;
    std::cout << "Hits Rate: " << hit_rate << "%" << std::endl;
    std::cout << "Miss Rate: " << miss_rate << "%" << std::endl;
    std::cout << std::endl;
    std::cout << "Each miss takes 5 cycles and each hit takes 1 cycle" << std::endl;
    std::cout << "Final Cycle Count: " << cycles << std::endl;
}

