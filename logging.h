#ifndef LOGGING_H
#define LOGGING_H

#include <stdio.h>
#include "run_test.h"

enum LEVEL_LOG
{
    DEBUG   = 1,
    INFO    = 2,
    WARNING = 3,
    ERROR   = 4,
};

struct logging
{
    FILE* set;

    const char* const file;

    const char* const func;

    int line;
};

void Log (struct logging parameter, enum LEVEL_LOG level, const char * const format, ...);

#endif // WORK WITH LOGGING_H
