#ifndef MY_OUTPUT_H
#define MY_OUTPUT_H

#include <stdbool.h>
#include <stdio.h>
#include "square_solver.h"
#include "run_test.h"

void output_roots (FILE* stream, struct result_of_test);
void print (struct test_settings set, struct pattern_for_tests pattern, \
           struct result_of_test real_result, bool truth);

#endif // WORK WITH MY_OUTPUT_H
