CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c89
SOURCES = $(wildcard *.c)
EXECUTABLE = monty

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@

clean:
	rm -f $(EXECUTABLE)

.PHONY: clean ## in case if there another file called clean
