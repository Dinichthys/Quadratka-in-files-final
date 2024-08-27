#ifndef SQUARE_SOLVER_H
#define SQUARE_SOLVER_H

#include <stdio.h>

enum SOLVE_SQUARE_RESULT
{
    NO_ROOTS  = 0,
    ONE_ROOT  = 1,
    TWO_ROOTS = 2,
    ALL       = 3,
    LINE      = 4
};

enum SOLVE_SQUARE_RESULT solve_lineal (double b, double c, double* x);
enum SOLVE_SQUARE_RESULT solve_square (FILE* stream_err, double a, double b, double c, double* x1, double* x2);

#endif // WORK WITH SQUARE_SOLVER_H
