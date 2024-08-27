#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "logging.h"
#include "settings_of_program.h"
#include "run_test.h"
#include "work_with_user.h"

int main (const int argc, char * const argv[])
{
    settings_of_program_t set = { .stream_in = stdin, .stream_out = stdout, .stream_err = stderr,
                                  .test_or_user = false, .verbose = false, .stop_program = false };

    parse_argv (argc, argv, &set);
    if (set.stop_program)
    {
        Log ({set.stream_err, __FILE__, __FUNCTION__, __LINE__}, ERROR,
              "The program stopped because of wrong parameters\n");
        fclose (set.stream_in);
        fclose (set.stream_out);
        return 0;
    }
    if (set.test_or_user)
    {
        Log ({set.stream_err, __FILE__, __FUNCTION__, __LINE__}, INFO, "The program started tests.\n");
        run_all_tests (set.stream_out, set.stream_err, set.verbose);
    }
    else
    {
        Log ({set.stream_err, __FILE__, __FUNCTION__, __LINE__}, INFO,
              "The program started working with user\n");
        user_version (set.stream_in, set.stream_out, set.stream_err);
    }
    fclose (set.stream_in);
    fclose (set.stream_out);
}
