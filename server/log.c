#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#include "log.h"

static FILE* log_file = NULL; /* Log FILE* */

static int print_timestamp() {
    time_t t;

    if (time(&t) < 0) {
        perror("time()");
        return 0;
    }

    char * ptr = asctime(localtime((const time_t *)&t));
    ptr[strlen(ptr) - 1] = '\0'; /* Remove the \n */

    fprintf(log_file, "[%s] ", ptr);
    return 1;
}

int log_initialize(const char * file, int log_level) {
    if (file == NULL)
        log_file = fopen(LOG_DEFAULT_FILE, "a");
    else
        log_file = fopen(file, "a");

    if (log_file)
        return 1;

    return 0;
}

int log_write(const char * fmt, ...) {
    int err;
    va_list vl;

    if (log_file == NULL)
        return -1;

    va_start(vl, fmt);
    print_timestamp();
    err = vfprintf(log_file, fmt, vl);
    va_end(vl);

    return err;
}
