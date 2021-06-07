#g++ ./Sources/*.cpp $(python3-config --cflags --libs --embed) -o ./Retro

OBJS=  main.o about.o binary_insertion_sort.o binary_search.o bubble_sort.o exponential_search.o fibonacci_search.o heap_sort.o indeed_data.o indeed_scraper.o insertion_sort.o jump_search.o linear_search.o menu.o merge_sort.o pathfinder_manager.o quick_sort.o rock_paper_scissor.o search.o search_manager.o selection_sort.o shell_sort.o sort.o sort_manager.o state.o state_manager.o user_page.o user_profile.o web_scraper_manager.o node.o pathfinder.o recursion_pathfinder.o
CC=g++
PY_CFLAGS=$(shell python3-config --cflags --libs --embed)

Retro: $(OBJS)
	g++ -o Retro $(OBJS) $(PY_CFLAGS)
	rm -f $(OBJS)		# remove *.o files

main.o:
	$(CC) -c ./Sources/main.cpp

about.o:
	g++ -c ./Sources/about.cpp

binary_insertion_sort.o:
	g++ -c ./Sources/binary_insertion_sort.cpp

binary_search.o:
	g++ -c ./Sources/binary_search.cpp

bubble_sort.o:
	g++ -c ./Sources/bubble_sort.cpp

exponential_search.o:
	g++ -c ./Sources/exponential_search.cpp

fibonacci_search.o:
	g++ -c ./Sources/fibonacci_search.cpp

heap_sort.o:
	g++ -c ./Sources/heap_sort.cpp

indeed_data.o:
	g++ -c ./Sources/indeed_data.cpp
	
indeed_scraper.o:
	g++ -c ./Sources/indeed_scraper.cpp $(PY_CFLAGS) 

insertion_sort.o:
	g++ -c ./Sources/insertion_sort.cpp

jump_search.o:
	g++ -c ./Sources/jump_search.cpp

linear_search.o:
	g++ -c ./Sources/linear_search.cpp

menu.o:
	g++ -c ./Sources/menu.cpp

merge_sort.o:
	g++ -c ./Sources/merge_sort.cpp

pathfinder_manager.o:
	g++ -c ./Sources/pathfinder_manager.cpp

quick_sort.o:
	g++ -c ./Sources/quick_sort.cpp

rock_paper_scissor.o:
	g++ -c ./Sources/rock_paper_scissor.cpp
	
search.o:
	g++ -c ./Sources/search.cpp

search_manager.o:
	g++ -c ./Sources/search_manager.cpp

selection_sort.o:
	g++ -c ./Sources/selection_sort.cpp

shell_sort.o:
	g++ -c ./Sources/shell_sort.cpp

sort.o:
	g++ -c ./Sources/sort.cpp

sort_manager.o:
	g++ -c ./Sources/sort_manager.cpp
	
state.o:
	g++ -c ./Sources/state.cpp

state_manager.o:
	g++ -c ./Sources/state_manager.cpp

user_page.o:
	g++ -c ./Sources/user_page.cpp

user_profile.o:
	g++ -c ./Sources/user_profile.cpp
	
web_scraper_manager.o:
	g++ -c ./Sources/web_scraper_manager.cpp

node.o:
	g++ -c ./Sources/node.cpp

pathfinder.o:
	g++ -c ./Sources/pathfinder.cpp

recursion_pathfinder.o:
	g++ -c ./Sources/recursion_pathfinder.cpp

clean: 
	rm -f core Retro $(OBJS)
