#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "my_output.h"
#include "run_test.h"
#include "square_solver.h"

void print_true_v  (struct test_settings set, struct pattern_for_tests pattern);
void print_false_v (struct test_settings set, struct pattern_for_tests pattern, \
                    struct result_of_test real_result);
void print_true    (struct test_settings set);
void print_false   (struct test_settings set, struct pattern_for_tests pattern, \
                    struct result_of_test real_result);

void output_roots (FILE * const stream, \
                   const struct result_of_test answer)
{
    assert (stream != NULL);

    switch (answer.result)
    {
        case NO_ROOTS:
        {
            fprintf (stream, "There is no roots\n");
            break;
        }
        case ONE_ROOT:
        {
            fprintf (stream, "Roots are similar and equal %.5lf\n", answer.x1);
            break;
        }
        case TWO_ROOTS:
        {
            fprintf (stream, "There are 2 roots\nx1 = %.5lf\nx2 = %.5lf\n", answer.x1, answer.x2);
            break;
        }
        case ALL:
        {
            fprintf (stream, "Roots are all real numbers\n");
            break;
        }
        case LINE:
        {
            fprintf (stream, "There is only one root because it is lineal equation\nx = %.5lf\n", answer.x1);
            break;
        }
        default:
        {
            fprintf (stream, "Invalid value for \"number_of_roots\" with type SOLVE_SQUARE_RESULT.\n");
            assert (0 && "Invalid SOLVE_SQUARE_RESULT value");
            break;
        }
    }
}

void print (const struct test_settings set, const struct pattern_for_tests pattern, \
            const struct result_of_test real_result, const bool truth)
{
    if (set.verbose)
    {
        if (truth)
        {
            print_true_v (set, pattern);
            return;
        }
        print_false_v (set, pattern, real_result);
        return;
    }
    if (truth)
    {
        print_true (set);
        return;
    }
    print_false (set, pattern, real_result);
}

void print_true_v (const struct test_settings set, const struct pattern_for_tests pattern)
{
    fprintf (set.stream_out, ":  Test № %d is succeeded  :\n"
                             " The coefficients:\n"
                             " a :\n"
                             " %.5lf\n"
                             " b :\n"
                             " %.5lf\n"
                             " c :\n"
                             " %.5lf\n"
                             " The result:\n"
                             , set.number_of_test, pattern.a, pattern.b, pattern.c);
    output_roots (set.stream_out, pattern.expect);
    fprintf (set.stream_out, "____________________________\n");
}

void print_false_v (const struct test_settings set, const struct pattern_for_tests pattern, \
                    const struct result_of_test real_result)
{
    fprintf (set.stream_out, ":  Error in test № %d.     :\n"
                             " The coefficients:\n"
                             " a :\n"
                             " %.5lf\n"
                             " b :\n"
                             " %.5lf\n"
                             " c :\n"
                             " %.5lf\n"
                             " Expected result:\n"
                             , set.number_of_test, pattern.a, pattern.b, pattern.c);
    output_roots (set.stream_out, pattern.expect);
    fprintf (set.stream_out, " Real result:\n");
    output_roots (set.stream_out, real_result);
    fprintf (set.stream_out, "____________________________\n");
}

void print_true (const struct test_settings set)
{
    fprintf (set.stream_out, ":  Test № %d is succeeded  :\n", set.number_of_test);
}

void print_false (const struct test_settings set, const struct pattern_for_tests pattern, \
                  const struct result_of_test real_result)
{
    fprintf (set.stream_out, ":  Error in test № %d.     :\n"
                         " Expected result:\n"
                         , set.number_of_test);
    output_roots (set.stream_out, pattern.expect);
    fprintf (set.stream_out, " Real result:\n");
    output_roots (set.stream_out, real_result);
}
