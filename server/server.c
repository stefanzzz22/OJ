#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shared/constants.h"
#include "server/log.h"

#define HELP_MESSAGE \
    "Usage: %s [PORT]\n" \
    "\tPORT\tPort number on which the server will run\n" \
    "\n"


static void show_help(int argc, char * argv[]) {
    printf(HELP_MESSAGE, argv[0]);
    exit(0);
}

static int parse_args(int argc, char * argv[], int * port) {
    int i, len;

    if (argc > 2) {
        return 0;
    }

    if (argc == 1) { /* Will run with default port. */
        *port = DEFAULT_PORT;
        return 1;
    }

    /* Check if argv[1] is an integer. */
    *port = 0;
    for (i = 0, len = strlen(argv[1]); i < len; i++) {
        *port = (*port) * 10 + argv[1][i] - '0';
        if (argv[1][i] < '0' || argv[1][i] > '9')
            return 0;
    }

    return 1;
}

static int server_loop(int sockfd, int port) {
    return 1;
}

static int server_initialize(int * sockfd) {
    return 1;
}

int main(int argc, char * argv[]) {
    int port, sfd;

    if (!parse_args(argc, argv, &port))
        show_help(argc, argv);

    log_initialize("log.txt", LOG_LEVEL_INFO);

    log_write("Test 1 %d 2 3 %d\n", 314, 152);

    if (!server_initialize(&sfd)) {
        fprintf(stderr, "Failed to initialize the server. Quitting...\n");
        exit(1);
    }

    if (!server_loop(sfd, port)) {
        fprintf(stderr, "Loop exited unexpectedly.\n");
    }

    fprintf(stderr, "Server terminated successfully.\n");

    return 0;
}
