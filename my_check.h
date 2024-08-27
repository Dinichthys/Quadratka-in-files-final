#ifndef MY_CHECK_H
#define MY_CHECK_H

#include <stdbool.h>
#include "check_double.h"
#include "print_error.h"

#define CHECK_EQUAL_INT(set, a, b, ...)             \
{                                                   \
    if ((a) != (b))                                 \
    {                                               \
        print_err (set.stream_err, __VA_ARGS__);    \
        set.test = false;                           \
    }                                               \
}

#define CHECK_EQUAL_DOUBLE(set, a, b, ...)          \
{                                                   \
    if (!is_equal(a, b))                            \
    {                                               \
        print_err (set.stream_err, __VA_ARGS__);    \
        set.test = false;                           \
    }                                               \
}

#define CHECK_NOT_NIL(set, a, ...)                  \
{                                                   \
    if (a == NULL)                                  \
    {                                               \
        print_err (set.stream_err, __VA_ARGS__);    \
        set.test = false;                           \
    }                                               \
}

#define CHECK_TRUE(set, x, ...)                     \
{                                                   \
    if (x)                                          \
    {                                               \
        print_err (set.stream_err, __VA_ARGS__);    \
        set.test = false;                           \
    }                                               \
}

#define CHECK_FALSE(set, x, ...)                    \
{                                                   \
    if (!x)                                         \
    {                                               \
        print_err (set.stream_err, __VA_ARGS__);    \
        set.test = false;                           \
    }                                               \
}

#endif // WORK WITH MY_CHECK_H
