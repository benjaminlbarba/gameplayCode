CC=gcc
CFLAGS=-I.
#DEPS = tcpsupport.h

#%.o: %.c #$(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)

allo: Inventory.o Item.o Main.o

all: Main Inventory Item 

# object files
Inventory.o: Inventory.cpp Inventory.h
	$(CC) Inventory.cpp -c -o $@

Item.o: Item.cpp Item.h
	clang -c Item.cpp -o $@

Main.o: Main.cpp
	clang -c Main.cpp -o $@

# executables
Item: Item.o
	$(CC) Item.o -c -o $@

Inventory : Inventory.o Item.o Inventory.h Item.h
	$(CC) Inventory.o Item.o -c -o $@

Main: Main.o Inventory.o Item.o
	g++ -o $@ Main.o Inventory.o Item.o 


#cleanup
clean:
	rm -rf *.o

clobber: clean
	rm -rf HumanActor Health *.o
		# TODO: may need to expand the line above

