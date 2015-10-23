CC = gcc
CFLAGS = -Wall -g -O3 -I.

SRV_INC = $(shell find server -type f -name \*.h)
CLT_INC = $(shell find client -type f -name \*.h)


.PHONY: all clean

all: bin/client bin/server

clean:
	rm -rf bin *~

bin/client: client/client.o
	mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@

client/client.o: client/client.c
	$(CC) -c $(CFLAGS) $< -o $@

bin/server: server/server.o server/log.o server/jail.o
	mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@

server/server.o: server/server.c $(SRV_INC)
	$(CC) -c $(CFLAGS) $< -o $@

server/log.o: server/log.c $(SRV_INC)
	$(CC) -c $(CFLAGS) $< -o $@

server/jail.o: server/jail.c $(SRV_INC)
	$(CC) -c $(CFLAGS) $< -o $@
