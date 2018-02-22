CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
# read all c files, generate their name
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=$(SOURCES:.c=)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
# compile .o file
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
clean:
	rm *.o $(EXECUTABLE)
