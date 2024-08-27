#ifndef MY_INPUT_H
#define MY_INPUT_H

#include <stdio.h>

int   clear_input        (FILE* stream);
bool  is_end_of_input    (FILE* stream);
bool  input_coefficients (FILE* stream_in, FILE* stream_out, FILE* stream_err, double* a, double* b, double* c);

#endif // WORK WITH MY_INPUT_H
