#include "intervals.h"
#include "SetIntervals.h"
#include "math.h"
#ifndef INTERVALS_INQEUALTY_H
#define INTERVALS_INQEUALTY_H
enum iq_type {
    GREATER,
    LESS,
    EQUAL,
    NOT_EQUAL,
    GREATER_EQUAL,
    LESS_EQUAL

};

typedef struct square_iqualty
{
    float a;
    float b;
    float c;
    enum iq_type type;
}SqIqualty;

SqIqualty* input_koef(float a,float b,float c,enum iq_type type_iq);
SetIntervals* find_one_decision(SqIqualty* iqt);
SetIntervals* find_system_decision(SetIntervals* ints1, SetIntervals* ints2);
SqIqualty* input_system(int n);


#endif //INTERVALS_INQEUALTY_H
