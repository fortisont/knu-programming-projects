#include "intervals.h"
#ifndef INTERVALS_SETINTERVALS_H
#define INTERVALS_SETINTERVALS_H
typedef struct setintervals
{
    int n;
    Interval* ints;
}SetIntervals;


void print_set(SetIntervals* set);
SetIntervals* set_mult(SetIntervals* ints1,SetIntervals* ints2);
SetIntervals* set_dif(SetIntervals* ints1, SetIntervals* ints2);
SetIntervals* set_add(SetIntervals* ints1, SetIntervals* ints2);
void rmdup(SetIntervals* set);

#endif //INTERVALS_SETINTERVALS_H
