#ifndef CACHELINE_H
#define CACHELINE_H

class Cacheline{
    
        
    long int tag;
    bool valid;
    int LRU;
    

    public:
        Cacheline();

        void set_tag(long int t);

        void set_valid(bool v);

        void set_LRU(long int time);

        long int get_tag();

        bool get_valid();

        int get_LRU();
};

#endif