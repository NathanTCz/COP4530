CC=g++
CFLAGS=-c
LFLAGS=
SOURCES1=main.cpp
SOURCES2=usestack.cpp Vector.h stack.h queue.h
OBJECTS1=$(SOURCES1:.cpp=.o)
OBJECTS2=$(SOURCES2:.cpp=.o)
EXECUTABLE1=recurse
EXECUTABLE2=usestack

all: $(SOURCES1) $(SOURCES2) $(EXECUTABLE1) $(EXECUTABLE2)
	rm -rf *~ *.o
	
$(EXECUTABLE1): $(OBJECTS1) 
	$(CC) $(LFLAGS) $(OBJECTS1) -o $@
  
$(EXECUTABLE2): $(OBJECTS2) 
	$(CC) $(LFLAGS) $(OBJECTS2) -o $@
  
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *~ $(EXECUTABLE1) $(EXECUTABLE2)  *.o
	clear
