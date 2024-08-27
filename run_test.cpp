#include <stdio.h>
#include <assert.h>
#include "my_assert.h"
#include "run_test.h"
#include "check_double.h"
#include "my_output.h"
#include "square_solver.h"
#include "logging.h"

void  swap     (result_of_test * res);
void  run_test (struct pattern_for_tests pattern, struct test_settings set);

void swap (result_of_test * const res)
{
    assert (res != NULL);

    if (((*res).result == TWO_ROOTS) && (((*res).x1 - (*res).x2) < 0))
    {
        double change = (*res).x1;
        (*res).x1 = (*res).x2;
        (*res).x2 = change;
    }
}

void run_test (const struct pattern_for_tests pattern, const struct test_settings set)
{
    struct result_of_test real_result = { NO_ROOTS, 0.0, 0.0 };

    real_result.result = solve_square (set.stream_err, pattern.a, pattern.b, pattern.c, &real_result.x1, &real_result.x2);

    swap (&real_result);

    ASSERT_EQUAL_INT(set, real_result.result, pattern.expect.result,
                     "Error in test %d. The program got wrong result.\n", set.number_of_test);
    ASSERT_EQUAL_DOUBLE(set, real_result.x1, pattern.expect.x1,
                        "Error in test %d. The program got one wrong root."
                        "x = %.5lf instead of x = %.5lf",
                        set.number_of_test, real_result.x1, pattern.expect.x1);
    ASSERT_EQUAL_DOUBLE(set, real_result.x2, pattern.expect.x2,
                        "Error in test %d. The program got one wrong root."
                        "x = %.5lf instead of x = %.5lf",
                        set.number_of_test, real_result.x2, pattern.expect.x2);
    if ((real_result.result != pattern.expect.result) ||
        (!(is_equal (real_result.x1, pattern.expect.x1))) ||
        (!(is_equal (real_result.x2, pattern.expect.x2))))
    {
        print (set, pattern, real_result, false);
        return;
    }
    print (set, pattern, real_result, true);
}

void run_all_tests (FILE * const stream_out, FILE * const stream_err, const bool verbose)
{
    assert (stream_out != NULL);
    assert (stream_err != NULL);

    const struct pattern_for_tests pattern[] =
    {
//        a        | b       | c        |                         result    | x1      | x2
//----------------------------------------------------------------------------------------------
        { 0,         0,        0,        (struct result_of_test) { ALL,       0,        0    } },
        { 0,         0,        3.5,      (struct result_of_test) { NO_ROOTS,  0,        0    } },
        { 0,         10,       4,        (struct result_of_test) { LINE,     -0.4,      0    } },
        { 0,         3,        0,        (struct result_of_test) { LINE,      0,        0    } },
        { 2.5,       5,        2.5,      (struct result_of_test) { ONE_ROOT, -1,        0    } },
        { 1,        -7,        12,       (struct result_of_test) { TWO_ROOTS, 4,        3    } },
        { 4,        -16,       15,       (struct result_of_test) { TWO_ROOTS, 2.5,      1.5  } },
        {-2,         5,        0,        (struct result_of_test) { TWO_ROOTS, 2.5,      0    } },
        { 1,        -2.82843,  2,        (struct result_of_test) { ONE_ROOT,  1.41421,  0    } },
        { 0.33333,  -0.66666,  0.33333,  (struct result_of_test) { ONE_ROOT,  1,        0    } },
        { 2.5,      -0.85833,  0.00833,  (struct result_of_test) { TWO_ROOTS, 0.33333,  0.01 } }
    };

    int number_of_test = 1;
    struct test_settings set = { stream_out, stream_err, number_of_test, verbose };

    for (; (long unsigned int) set.number_of_test <= sizeof (pattern) / sizeof (pattern [0]); set.number_of_test++)
    {
        run_test (pattern [set.number_of_test - 1], set);
        Log ({stream_err, __FILE__, __FUNCTION__, __LINE__}, INFO,
              "The program started test %d\n", set.number_of_test);
    }

    fprintf (stream_out, "All tests are done\n");
}
