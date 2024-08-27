#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <getopt.h>
#include "print_help.h"
#include "settings_of_program.h"

void parse_argv (const int argc, char * const argv[], settings_of_program_t * const set)
{
    assert (argv != NULL);
    assert (set != NULL);

    const struct option modifications [] =
    {
        {"tests",   0, 0, 't'},
        {"user",    0, 0, 'u'},
        {"verbose", 0, 0, 'v'},
        {"help",    0, 0, 'h'},
        {0,         0, 0,  0 }
    };

    int mode = 0;
    int long_index = 0;
    int count_iterate = 0;

    while (mode != -1)
    {
        count_iterate++;
        mode = getopt_long (argc, argv, "+tuo:i:e:vh", modifications, &long_index);
        switch (mode)
        {
            case 't':
            {
                set->test_or_user = true;
                break;
            }
            case 'u':
            {
                break;
            }
            case 'o':
            {
                set->stream_out = fopen (optarg, "w");
                count_iterate++;
                break;
            }
            case 'i':
            {
                set->stream_in = fopen (optarg, "r");
                if (!(set->stream_in))
                {
                    mode = -1;
                    set->stop_program = true;
                    printf ("There is no files with name %s\n", optarg);
                }
                count_iterate++;
                break;
            }
            case 'e':
            {
                set->stream_err = fopen (optarg, "w");
                count_iterate++;
                break;
            }
            case 'v':
            {
                set->verbose = true;
                break;
            }
            case 'h':
            {
                print_help ();
                mode = -1;
                set->stop_program = true;
                break;
            }
            case -1:
            {
                if (argc != count_iterate)
                {
                    printf ("There are odd symbols in the terminal.\n");
                    mode = -1;
                    set->stop_program = true;
                    assert (0 && "There are odd symbols in the terminal.\n");
                }
                break;
            }
            default:
            {
                printf("Invalid name of command in the terminal.\n");
                mode = -1;
                set->stop_program = true;
                assert (0 && "Invalid name of command in the terminal.\n");
                break;
            }
        }
    }
}
