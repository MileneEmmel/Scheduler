#ifndef TIMER_H
#define TIMER_H

#include <stdbool.h>
#define QUANTUM 10

void *th_timer();
void timer_start();
int timer_get_time();
bool timer_flag_slice();

#endif // TIMER_H
