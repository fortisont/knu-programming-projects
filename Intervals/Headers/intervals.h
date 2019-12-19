#include <stdio.h>
#include <stdlib.h>
#ifndef INTERVALS_INTERVALS_H
#define INTERVALS_INTERVALS_H


enum Type{
    EMPTY,
    DEGENERATE,
    OPEN,
    CLOSED,
    LEFT_OPEN,
    RIGHT_OPEN,
    LEFT_UNBOUNDED_RIGHT_OPEN,
    LEFT_UNBOUNDED_RIGHT_CLOSED,
    RIGHT_UNBOUNDED_LEFT_OPEN,
    RIGHT_UNBOUNDED_LEFT_CLOSED,
    UNBOUNDED,

};





typedef struct interval
{
    enum Type interval_type;
    float a;
    float b;

}Interval;



void output(Interval* inter);
Interval* input(enum Type int_type,float a, float b);
enum Type int_type(enum Type type_1,enum Type type_2);
Interval* mult(Interval* inter_1,Interval* inter_2);
enum Type part_type(char el,Interval* inter);
int find_a(Interval* in1,Interval* in2);
int find_b(Interval* in1,Interval* in2);
Interval* addition(Interval* inter_1, Interval* inter_2);
Interval* difference(Interval* inter_1, Interval* inter_2);
#endif //INTERVALS_INTERVALS_H
