TARGET = prog.out
LIBS = -lSDL2main -lSDL2
CC = gcc
CFLAGS = -fPIC -Wall -Werror -Wextra -Wno-unused-result -Wno-unused-parameter -O2

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS)  $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
