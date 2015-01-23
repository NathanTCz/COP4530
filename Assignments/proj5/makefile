CC=g++
CFLAGS=-O3 -fopenmp -c 
LFLAGS= -fopenmp
SOURCES=main.cpp parse.cpp play.cpp database.cpp cputime.cpp

OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=Analyze

all: $(SOURCES) $(EXECUTABLE)
	rm -rf *~ *.o
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LFLAGS) $(OBJECTS) -o $@
  
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *~ $(EXECUTABLE)  *.o
	clear