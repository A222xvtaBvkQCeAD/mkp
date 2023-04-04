driver: driver.cpp item.o knapsack.o chromosome.o mkp.o
	g++ item.o knapsack.o chromosome.o mkp.o driver.cpp -o driver
mkp: mkp.cpp mkp.h knapsack.o chromosome.o
	g++ knapsack.o chromosome.o -c mkp.cpp
chromosome: chromosome.cpp chromosome.h item.o knapsack.o
	g++ item.o knapsack.o -c chromosome.cpp
knapsack: knapsack.cpp knapsack.h item.o
	g++ item.o -c knapsack.cpp
item: item.cpp item.h
	g++ -c item.cpp
clean:
	rm *.o driver
