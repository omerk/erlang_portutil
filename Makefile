CC=gcc
EILOCN:=$(shell find /usr/local/lib/erlang /usr/lib/erlang -name ei.h -printf '%h' 2> /dev/null | head -1)
CFLAGS=-Wall -pedantic -I$(EILOCN)

all: port_comms.o

port_comms.o: port_comms.h

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o

