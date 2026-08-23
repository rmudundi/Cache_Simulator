#include <cacheline.h>

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

        int tag();

        int index();

        int offset();

        int num_sets();

        int get_counter();
};