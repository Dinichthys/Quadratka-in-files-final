#ifndef MY_ASSERT_H
#define MY_ASSERT_H

#include <stdbool.h>
#include "check_double.h"
#include "print_error.h"

#define ASSERT_EQUAL_INT(set, a, b, ...)            \
{                                                   \
    if ((a) != (b))                                 \
    {                                               \
        print_err (set.stream_err, __VA_ARGS__);    \
        return;                                     \
    }                                               \
}

#define ASSERT_EQUAL_DOUBLE(set, a, b, ...)         \
{                                                   \
    if (!is_equal(a, b))                            \
    {                                               \
        print_err (set.stream_err, __VA_ARGS__);    \
        return;                                     \
    }                                               \
}

#define ASSERT_NOT_NIL(set, a, ...)                 \
{                                                   \
    if (a == NULL)                                  \
    {                                               \
        print_err (set.stream_err, __VA_ARGS__);    \
        return;                                     \
    }                                               \
}

#define ASSERT_TRUE(set, x, ...)                    \
{                                                   \
    if (!x)                                         \
    {                                               \
        print_err (set.stream_err, __VA_ARGS__);    \
        return;                                     \
    }                                               \
}

#define ASSERT_FALSE(set, x, ...)                   \
{                                                   \
    if (x)                                          \
    {                                               \
        print_err (set.stream_err, __VA_ARGS__);    \
        return;                                     \
    }                                               \
}

#endif // WORK WITH MY_ASSERT_H
