try: queue.o main.o graph.o map.o
	cc queue.o main.o graph.o map.o -o try
queue.o: queue.h queue.c
	cc -Wall -c queue.c
main.o: main.c graph.h
	cc -Wall -c main.c
map.o: map.c graph.h
	cc -Wall -c map.c
graph.o: queue.h graph.c graph.h
	cc -Wall -c graph.c
