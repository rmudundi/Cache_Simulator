output: main.o cache.o cacheset.o cacheline.o stats.o hash.o main_1.o
	g++ main.o cache.o cacheset.o cacheline.o stats.o hash.o main_1.o -o a.out

main.o: src/main.cpp
	g++ -g -c -I include src/main.cpp

main_1.o: src_1/main_1.cpp
	g++ -g -c -I include -I include_1 src_1/main_1.cpp

cache.o: src/cache.cpp include/cache.h
	g++ -g -c -I include src/cache.cpp

cacheset.o: src/cacheset.cpp include/cacheset.h
	g++ -g -c -I include src/cacheset.cpp 

cacheline.o: src/cacheline.cpp include/cacheline.h
	g++ -g -c -I include src/cacheline.cpp

stats.o: src/stats.cpp include/stats.h
	g++ -g -c -I include src/stats.cpp

hash.o: src_1/hash.cpp include_1/hash.h
	g++ -g -c -I include -I include_1 src_1/hash.cpp
	
clean: 
	rm *.o a.out