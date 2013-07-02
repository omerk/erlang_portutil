CC=gcc
EILOCN:=$(shell find /usr/local/lib/erlang /usr/lib/erlang -name ei.h -printf '%h' 2> /dev/null | head -1)
CFLAGS=-Wall -pedantic -I$(EILOCN)

default: port_comms.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

port_comms.o: port_comms.h

