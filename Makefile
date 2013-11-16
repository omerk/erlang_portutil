CC=gcc
EILOCN:=$(shell find /usr/local/lib/erlang /usr/lib/erlang -name ei.h -printf '%h\n' 2> /dev/null | head -1)
CFLAGS=-Wall -std=c99 -I$(EILOCN)

all: portutil.o

portutil.o: portutil.h

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o

