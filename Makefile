CC=gcc
EIFILE:=$(shell find /usr/local/lib/erlang /usr/lib/erlang -name ei.h 2> /dev/null | head -1)
EILOCN:=$(shell dirname $(EIFILE) ) 
CFLAGS=-Wall -std=c99 -I$(EILOCN)

all: portutil.o

portutil.o: portutil.h

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o

