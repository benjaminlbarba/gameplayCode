CC=gcc
CFLAGS=-I.

allo: HumanActor.o Health.o Main.o

all: HumanActor Health Main

# object files
Health.o: Health.cpp Health.h
	$(CC) Health.cpp -c -o $@

HumanActor.o: HumanActor.cpp HumanActor.h gameObject.h
	clang -c HumanActor.cpp -o $@

Main.o: Main.cpp
	clang -c Main.cpp -o $@

# executables
Health: Health.o
	$(CC) Health.o -c -o $@

HumanActor : HumanActor.o Health.o HumanActor.h Health.h
	$(CC) HumanActor.o Health.o -c -o $@

Main: Main.o HumanActor.o Health.o
	g++ -o $@ Main.o HumanActor.o Health.o 


#cleanup
clean:
	rm -rf *.o

clobber: clean
	rm -rf HumanActor Health *.o
		# TODO: may need to expand the line above

