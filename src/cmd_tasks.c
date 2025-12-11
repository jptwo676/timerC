#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../include/time_management.h"

// functions to be called when using cmd options or flags

int cmd_time_increase(char *arg)
{
  int sec_counter = 0;
  int min_counter = 0;
  
  int min_target = atoi(arg);
  int increasing_check = 0;

  while(increasing_check == 0)
    {
      printf("time : %02d:%02d elapsed / target time %02d:%02d\n",
             min_counter, sec_counter, min_target, 0);
      sleep(1);

      // end timer
      if(min_counter == min_target)
        {
          return 0;
        }
      // reset seconds
      if(sec_counter == 59)
        {
          min_counter++;
          sec_counter = 0;
        }
      else
        {
          sec_counter++;
        }
    }
  return 1;
}

