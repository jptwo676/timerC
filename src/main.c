#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "../include/time_management.h"

// these are separated in case of future features for each usage.
#include "../include/cmd_tasks.h"
#include "../include/interactive_tasks.h"

static int verbose_flag;

// move this upwards
static struct option long_options[] =
  // flags
  {
    {"verbose", no_argument, &verbose_flag, 1},
    {"brief",   no_argument, &verbose_flag, 0},
    {"help",    no_argument, &verbose_flag, 1},
    // options
    {"decrease", required_argument, 0, 'd'},
    {"increase", required_argument, 0, 'i'},
    {"interactive", no_argument, 0 , 'I'},
    {0, 0, 0, 0}
  };

// TODO(jptwo676) construct this func
void print_help()
{
  printf("This is helpful.\n");
}

int main(int argc, char *argv[])
{
  // doing command line args
  int option;  

  while(1)
    {
      int option_index = 0;

      option = getopt_long(argc, argv, "d:i:I", long_options,
                           &option_index);
      // -1 means all cmd have been processed
      if(option == -1)
        break;

      switch(option)
        {
          // 0 means it is a flag
        case 0:
          if(long_options[option_index].flag != 0)
            break;
          printf("option %s", long_options[option_index].name);
          if(optarg)
            printf(" with arg %s", optarg);
          printf("\n");
          break;

        case 'd':
          /* calls cmd_time_increase because when in the background
             it acts the same way */
          cmd_time_increase(optarg);
          break;

        case 'i':
          cmd_time_increase(optarg);
          break;

        case 'I':
          printf("option -I with values '%s'\n", optarg);
          break;
          
        default:
          abort();
        }
      return 0;
    }
}

