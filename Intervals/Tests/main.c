#include <stdio.h>
#include "intervals.h"
#include "SetIntervals.h"
#include "Inqeualty.h"

int main() {
    printf("-------Diffrent intervals tests-------\n");
    Interval* in1 = input(LEFT_OPEN,1,3);
    printf("Interval 1 -> ");
    output(in1);
    Interval* in2 = input(CLOSED,2,5);
    printf("Interval 2 -> ");
    output(in2);
    printf("Multiply -> ");
    Interval* mlt = mult(in1,in2);
    output(mlt);
    printf("Addition -> ");
    Interval* add = addition(in1,in2);
    output(add);
    printf("Difference -> \n");
    Interval* dif = difference(in1,in2);
    output(&dif[0]);
    output(&dif[1]);

    printf("------Infinty test------\n");
    // на місці нескінченності вводиться значення 0,але далі у функціях якщо порвнються
    //значення,то на місці нескінченності присваюється число 999999999
    Interval* in4 = input(LEFT_UNBOUNDED_RIGHT_OPEN,0,3);
    Interval* in5 = input(RIGHT_UNBOUNDED_LEFT_CLOSED,1,0);
    Interval* in6 = input(UNBOUNDED,0,0);
    Interval* in7 = input(RIGHT_UNBOUNDED_LEFT_CLOSED,0,0);
    Interval* in8 = input(OPEN,2,6);
    Interval* in9 = input(LEFT_UNBOUNDED_RIGHT_CLOSED,0,1);
    printf("Interval 1 -> ");
    output(in4);
    printf("Interval 2 -> ");
    output(in5);
    printf("Multiply -> ");
    Interval* mlt3 = mult(in4,in5);
    output(mlt3);
    printf("Interval 1 -> ");
    output(in6);
    printf("Interval 2 -> ");
    output(in7);
    printf("Addition -> ");
    Interval* add3 = addition(in6,in7);
    output(add3);
    printf("Interval 1 -> ");
    output(in8);
    printf("Interval 2 -> ");
    output(in9);
    Interval* diff2 = difference(in8,in9);
    printf("Difference -> ");
    output(&diff2[1]);
    output(&diff2[0]);



    printf("------Test interval with point------ \n");
    Interval* in3 = input(DEGENERATE,1,1);
    printf("Single point -> ");
    output(in3);
    printf("Interval -> ");
    output(in1);
    Interval* mlt2 = mult(in3,in1);
    printf("Multiply -> ");
    output(&mlt2[0]);
    output(&mlt2[1]);
    Interval* add2 = addition(in3,in1);
    printf("Addition -> ");
    output(add2);
    Interval* dif2 = difference(in3,in1);
    printf("Difference -> \n");
    output(&dif2[0]);
    output(&dif2[1]);

    printf("------The solution of the system of square inequalities------\n");
    //x^2 - 3x - 88 >= 0
    //x^2 - 7x - 60 < 0
    //в сиситемі заодно перевіряється й перетин в масиві інтервалів
    SqIqualty* iq1 = input_koef(1,-3,-88,GREATER_EQUAL);
    SqIqualty* iq2 = input_koef(1,-7,-60,LESS);
    SetIntervals* decision1;
    SetIntervals* decision2;
    SetIntervals* decision;
    decision1 = find_one_decision(iq1);
    decision2 = find_one_decision(iq2);
    decision = find_system_decision(decision1,decision2);
    printf("Decision - > \n");
    print_set(decision);


}