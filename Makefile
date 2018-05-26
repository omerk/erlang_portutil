CC=gcc
EILOCN:=$(shell erl -hidden -eval 'io:format("~p", [code:root_dir()]).' -s erlang halt | grep '1>' | sed 's/"\(.*\)"1>/\1\/usr\/include/')
CFLAGS=-Wall -std=c99 -I$(EILOCN)

all: portutil.o

portutil.o: portutil.h

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o

