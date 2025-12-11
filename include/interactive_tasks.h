#ifndef TASK_RELATED
#define TASK_RELATED

typedef struct Task
{
  char name[50];
  int time_sec;
} Task;

int int_time_increase(int (*p_get_min) (void));

int int_time_decrease(int (*p_get_min) (void));

#endif // TASK_RELATED
