#include <iostream>
#include <vector>


class Stats{
    int instructions;
    double hit;
    double miss;
    double hit_rate;
    double miss_rate;
    int cycles;
    long int time; //measure in microseconds

    public: 

        Stats();

        void update_hit();

        void update_miss();

        void count_inst();

        void set_cycles(long int counter);

        void set_clocktime(long int time);

        long int clocktime();

        void rates();

        void results(Stats v, Stats h);


};