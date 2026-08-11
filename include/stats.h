#include <iostream>
#include <vector>


class Stats{
    int instructions;
    double hit;
    double miss;
    double hit_rate;
    double miss_rate;
    int cycles;

    public: 

        Stats();

        void update_hit();

        void update_miss();

        void count_inst();

        void set_cycles(long int counter);

        void rates();

        void print_results();


};