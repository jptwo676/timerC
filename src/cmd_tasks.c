#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../include/time_management.h"

// functions to be called when using cmd options or flags

int cmd_time_increase(char *arg)
{
  int sec_counter = 0;
  int min_counter = 0;
  
  int min_init = atoi(arg);
  if(min_init == 0)
    {
      printf("Invalid value, only numbers allowed as argument.\n");
      return 0;
    }
  int increasing_check = 0;

  while(increasing_check == 0)
    {
      sleep(1);

      // end timer
      if(min_counter == min_init)
        {
          printf("\nDone! %d minute(s) have passed.", min_init);
          return 1;
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
  return 0;
}

