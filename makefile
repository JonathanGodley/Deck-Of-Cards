CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=DeckOfCardsDemo.cpp DeckOfCards.cpp LinkedList.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=DeckOfCardsDemo.exe

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core