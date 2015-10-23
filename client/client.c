#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shared/constants.h"

#define HELP_MESSAGE \
    "Usage: %s ADDRESS [PORT]\n" \
    "\tADDRESS\tIP or Hostname of the server\n" \
    "\tPORT\tPort number on which the server runs\n" \
    "\n"

static void show_help(int argc, char * argv[]) {
    printf(HELP_MESSAGE, argv[0]);
    exit(0);
}

static int parse_args(int argc, char * argv[], int * port) {
    int i, len;

    if (argc > 3) {
        return 0;
    }

    if (argc == 2) {
        /* Will run with default port. */
        *port = DEFAULT_PORT;
        return 1;
    }
    
    if (argc == 1) {
        /* No server address specified. */
        return 0;
    }

    /* Check if argv[2] is an integer. */
    *port = 0;
    for (i = 0, len = strlen(argv[2]); i < len; i++) {
        *port = (*port) * 10 + argv[2][i] - '0';
        if (argv[2][i] < '0' || argv[2][i] > '9')
            return 0;
    }

    return 1;
}

int main(int argc, char * argv[]) {
    int port;

    if (!parse_args(argc, argv, &port))
        show_help(argc, argv);

    return 0;
}
