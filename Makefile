#g++ ./Sources/*.cpp $(python3-config --cflags --libs --embed) -o ./Retro

OBJS = main.o about.o 
CC = g++

RetroOut: $(OBJS)
	g++ -o RetroOut $(OBJS)

main.o:
	$(CC) -c main.cpp

about.o:
	$(CC) -c about.cpp

binary_insertion_sort.o:
	$(CC) -c binary_insertion_sort.cpp

binary_search.o:
	$(CC) -c binary_search.cpp

bubble_sort.o:
	$(CC) -c bubble_sort.cpp

clean:
	rm -f core RetroOut $(OBJS)
