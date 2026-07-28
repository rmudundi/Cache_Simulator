output: main.o cache.o line_LRU.o stat.o
	g++ cache.o line_LRU.o stat.o -o output

main.o: main.cpp
	g++ -c main.cpp

cache.o: cache.cpp cache.h
	g++ -c cache.cpp

line_LRU.o: line_LRU.cpp line_LRU.h
	g++ -c line_LRU.cpp

clean: 
	rm *.o output