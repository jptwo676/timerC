#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../include/time_management.h"

// 
// 0 to x
int int_time_increase(int (*p_get_min) (void))
{
  int sec_counter = 0;
  int min_counter = 0;

  int min_target = p_get_min();
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

// x to 0
int int_time_decrease(int (*p_get_min) (void))
{
  // -1, because if you specify 5 min the count starts at 4:59
  // 4 minutes will be displayed :)
  int min_init = p_get_min() - 1;
  int sec_counter = 59;
  int min_counter = min_init;
  int decreasing_check = 0;

  /* first run display 
  /* since min_init is the value of the arg - 1, sometimes we need
  /* to use + 1 */
  printf("time : %02d:%02d remaining / ",
         min_init + 1, 0);
  
  printf("initial time : %02d:%02d\n",
         min_init + 1, 0);
  
  while(decreasing_check == 0)
    {
      printf("time : %02d:%02d remaining / initial time : %02d:%02d\n",
             min_counter, sec_counter, min_init + 1, 0);
      sleep(1);
      
      // end timer
      if(min_counter == 0 && sec_counter == 0)
        {
          return 0;
        }
      // resets seconds
      if(sec_counter == 0)
        {
          min_counter--;
          sec_counter =  59;
        }
      else
        {
          sec_counter--;
        }
    }
  return 1;
}



