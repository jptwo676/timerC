#include <stdio.h>
#include <stdlib.h>

// read input char by char until a \n or EOF
int readln_str(char str[], int max_len)
{
  int ch;
  int i = 0;
  char ch_char;
  
  // 0  when done
  int remain_check = 1;
  while(remain_check)
    {
      ch = getchar();
      ch_char = (char)ch;
      if((ch == '\n') || (ch == EOF))
        {
          remain_check = 0;
            str[i] = '\0';
            return 0;
        }
      else if(i < max_len -1)
        {
          str[i] = ch_char;
          i++;
        }
    }
  return 1;
}

// get and convert a str to an int
int get_min_int()
{
  int time_int;
  char time_str[3];
  int r_time_str = 1;
  while(r_time_str != 0)
    {
      printf("Enter task duration (min 1, max 60)\n");
      // 0 means success
      r_time_str = readln_str(time_str, 3);

    }
  // 0 means failure
  time_int = atoi(time_str);
  if(time_int == 0)
    {
      printf("Invalid value, only numbers allowed.\n");
      return 0;
    }
  else
    {
      return time_int;
    }
}

// convert minutes to seconds
// 1 = 60
// 25 = 25*60
int minutes_to_seconds(int minutes)
{
  int seconds = -1;
  // 60 minutes is the limit, 60 * 60 == 3600
  if((60 * minutes) <= 3600)
    {
      seconds = 60 * minutes;
      return seconds;
    }
  return seconds;
}
