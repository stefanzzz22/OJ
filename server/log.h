#ifndef LOG_H
#define LOG_H

#define LOG_LEVEL_INFO          3
#define LOG_LEVEL_DEBUG         2
#define LOG_LEVEL_WARN          1
#define LOG_LEVEL_ERROR         0

#define LOG_DEFAULT_FILE        "/var/log/oj.log"

int log_initialize(const char * file, int log_level);
int log_write(const char * fmt, ...);


#endif /* LOG_H */
