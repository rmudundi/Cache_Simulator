#ifndef HASH_H
#define HASH_H
#include <cacheline.h>
#include <vector>
#include <unordered_map>

class Hash{

    int cache_size;
    int block_size;
    int num_set;
    int associativity;
    int o;
    int i;
    int t;

    long int counter;

    std::unordered_map<int, std::vector<Cacheline>> hashmap;

    public:

        Hash(int c, int b, int a, int addr);

        int search(int i, int t, int& m);

        void evict(int i, int t);

        int tag();

        int index();

        int offset();

        int num_sets();

        int get_counter();

};

#endif