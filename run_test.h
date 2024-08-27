#ifndef RUN_TEST_H
#define RUN_TEST_H

#include <stdbool.h>
#include <stdio.h>
#include "square_solver.h"

struct result_of_test
{
    enum   SOLVE_SQUARE_RESULT result;
    double x1;
    double x2;
};

struct pattern_for_tests
{
    double a;
    double b;
    double c;

    struct result_of_test expect;
};

struct test_settings
{
    FILE* stream_out;
    FILE* stream_err;

    int number_of_test;

    bool verbose;

    bool test;
};

void  run_all_tests (FILE* stream_out, FILE* stream_err, bool verbose);

#endif // WORK WITH RUN_TEST_H
