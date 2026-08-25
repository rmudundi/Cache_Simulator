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

void Stats::set_clocktime(long int t){
    time = t;
}

long int Stats::clocktime(){
    return time;
}

void Stats::results(Stats v, Stats h){
    std::cout << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Final Stats:" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Total # of Instructions: " << v.instructions << std::endl;
    std::cout << "Miss = 5 cycles" << std::endl;
    std::cout << "Hit = 1 cycle" << std::endl;
    std::cout << "            -----------------------------" << std::endl;
    std::cout << "                Vector    |     Hash     " << std::endl;
    std::cout << "            -----------------------------" << std::endl;
    std::cout << "Hits Rate:       " << v.hit_rate << "%" << "      |      " << h.hit_rate << "%" << std::endl;
    std::cout << "Miss Rate:       " << v.miss_rate << "%" << "      |      " << h.miss_rate << "%" << std::endl;
    std::cout << "# of Cycles:     " << v.cycles  << "       |       " << h.cycles << std::endl;
    std::cout << "Execution Time:  " << v.time << " us" << "   |      " << h.time << " us" << std::endl;
    //std::cout << std::endl;
    
    //std::cout << "H: " << h.hit << " " << h.miss << std::endl;
    //std::cout << "V: " << v.hit << " " << v.miss << std::endl;
}

