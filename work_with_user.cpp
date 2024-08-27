#include <assert.h>
#include <stdio.h>
#include "run_test.h"
#include "work_with_user.h"
#include "square_solver.h"
#include "my_input.h"
#include "my_output.h"
#include "logging.h"

void user_version (FILE * const stream_in, FILE * const stream_out, FILE * const stream_err)
{
    assert (stream_in != NULL);
    assert (stream_out != NULL);
    assert (stream_in != stream_out);

    struct result_of_test answer = { NO_ROOTS, 0.0, 0.0 };
    double a  = 0.0;
    double b  = 0.0;
    double c  = 0.0;

    if (!(input_coefficients (stream_in, stream_out, stream_err, &a, &b, &c)))
    {
        Log ({stream_err, __FILE__, __FUNCTION__, __LINE__}, WARNING,
              "The program didn't get the coefficients\n");
        return;
    }
    answer.result = solve_square (stream_err, a, b, c, &(answer.x1), &(answer.x2));
    output_roots (stream_out, answer);
}
