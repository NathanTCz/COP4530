CC=g++
CFLAGS=-O3 -c
LFLAGS=
SOURCES=main.cpp parse.cpp play.cpp database.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Analyze

all: $(SOURCES) $(EXECUTABLE)
	rm -rf *~ *.o
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *~ $(EXECUTABLE) *.o outfile.txt
	clear