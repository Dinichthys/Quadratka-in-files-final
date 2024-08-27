#include <stdarg.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "logging.h"

void level_to_str (FILE* stream,  enum LEVEL_LOG level);

void level_to_str (FILE* stream, enum LEVEL_LOG level)
{
    switch (level)
    {
        case DEBUG:
        {
            fprintf (stream, "[%s] \n", "DEBUG");
            break;
        }
        case INFO:
        {
            fprintf (stream, "[%s] \n", "INFO");
            break;
        }
        case WARNING:
        {
            fprintf (stream, "[%s] \n", "WARNING");
            break;
        }
        case ERROR:
        {
            fprintf (stream, "[%s] \n", "ERROR");
            break;
        }
        default:
        {
            assert (0 && "Program got wrong level of logging in function log");
            break;
        }
    }
}


void Log (struct logging settings, enum LEVEL_LOG level, const char * const format, ...)
{
    level_to_str (settings.set, level);
    fprintf (settings.set, "[%s] \nIn function [%s] \nIn line %d\n",
             settings.file, settings.func, settings.line);
    va_list param;
    va_start (param, format);
    vfprintf (settings.set, format, param);
    va_end (param);
}
