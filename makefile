HELL = /usr/bin/env bash
CFLAGS = -std=gnu99 -Wall -Wextra -Werror
SERVER = server.c net.c
all:
	gcc $(CFLAGS) $(SERVER) -o hinfosvc