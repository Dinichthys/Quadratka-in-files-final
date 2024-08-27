#include <stdio.h>
#include "print_help.h"

void print_help (void)
{
    printf (" There is list of parameters of that program.\n"
                            " \"--test\" or \"-t\"    :"
                            " the program is starting testing by the tests.\n"
                            " \"--user\" or \"-u\"    :"
                            " the program is starting working with user.\n"
                            " \"-i\"                :"
                            " you can change the stream of input"
                            " and write the name of place of input after it.\n"
                            " \"-o\"                :"
                            " you can change the stream of output"
                            " and write the name of place of output after it.\n"
                            " \"-e\"                :"
                            " you can change the stream of output for errors"
                            " and write the name of place of output after it.\n"
                            " \"--verbose\" or \"-v\" :"
                            " makes the analytic investigation verbose.\n");
}
