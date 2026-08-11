output: main.o cache.o cacheset.o cacheline.o stats.o
	g++ main.o cache.o cacheset.o cacheline.o stats.o -o a.out

main.o: src/main.cpp
	g++ -g -c -I include src/main.cpp

cache.o: src/cache.cpp include/cache.h
	g++ -g -c -I include src/cache.cpp

cacheset.o: src/cacheset.cpp include/cacheset.h
	g++ -g -c -I include src/cacheset.cpp 

cacheline.o: src/cacheline.cpp include/cacheline.h
	g++ -g -c -I include src/cacheline.cpp

stats.o: src/stats.cpp include/stats.h
	g++ -g -c -I include src/stats.cpp
	
clean: 
	rm *.o a.out