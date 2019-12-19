#include "Inqeualty.h"


//функція знаходження розв`язку однієї квадратної нерівності
SetIntervals* find_one_decision(SqIqualty* iqt)
{
    SetIntervals* res = (SetIntervals*) malloc(sizeof(SetIntervals));
    float d,root1,root2;
    d = iqt->b * iqt->b - 4 * iqt->a * iqt->c;
    if (d >= 0)
    {
        root1 = (-iqt->b - sqrtf(d)) / 2 * iqt->a;
        root2 = (-iqt->b + sqrtf(d)) / 2 * iqt->a;
    }
    else{
        printf("Complex roots");
        return 0;
    }

    switch(iqt->type)
    {
        case GREATER:
        {
            if (iqt->a > 0)
            {
                if (d > 0)
                {
                    res->ints = (Interval*) malloc(sizeof(Interval) * 2);
                    Interval* int1;
                    Interval* int2;
                    int1 = input(LEFT_UNBOUNDED_RIGHT_OPEN,0,root1);
                    int2 = input(RIGHT_UNBOUNDED_LEFT_OPEN,root2,0);
                    res->ints[0] = *int1;
                    res->ints[1] = *int2;
                    res->n = 2;
                    return res;
                }
                if (d == 0){
                    res->ints = (Interval*) malloc(sizeof(Interval));
                    Interval* int1;
                    int1 = input(UNBOUNDED,0,0);
                    res->ints = int1;
                    res->n = 1;
                    return res;
                }

            }
            if (iqt->a < 0)
            {
                if (d > 0)
                {
                    res->ints = (Interval*) malloc(sizeof(Interval));
                    Interval* int1;
                    int1 = input(OPEN,root1,root2);
                    res->ints = int1;
                    res->n = 1;
                    return res;
                }
                if (d == 0){
                    res->ints = (Interval*) malloc(sizeof(Interval));
                    Interval* int1;
                    int1 = input(EMPTY,0,0);
                    res->ints = int1;
                    res->n = 1;
                    return res;
                }

            }
            if (iqt->a == 0)
            {
                float root;
                root = -iqt->c / iqt->b;

                res->ints = (Interval*) malloc(sizeof(Interval));
                Interval* int1;
                int1 = input(RIGHT_UNBOUNDED_LEFT_OPEN,root,0);
                res->ints = int1;
                res->n = 1;
                return res;
            }

        }
        case LESS:
        {
            if (iqt->a > 0)
            {
                if (d > 0)
                {
                    res->ints = (Interval*) malloc(sizeof(Interval));
                    Interval* int1;
                    int1 = input(OPEN,root1,root2);
                    res->ints = int1;
                    res->n = 1;
                    return res;
                }
                if (d == 0){
                    res->ints = (Interval*) malloc(sizeof(Interval));
                    Interval* int1;
                    int1 = input(EMPTY,0,0);
                    res->ints = int1;
                    res->n = 1;
                    return res;
                }

            }
            if (iqt->a < 0)
            {
                if (d > 0)
                {
                    res->ints = (Interval*) malloc(sizeof(Interval) * 2);
                    Interval* int1;
                    Interval* int2;
                    int1 = input(LEFT_UNBOUNDED_RIGHT_OPEN,0,root1);
                    int2 = input(RIGHT_UNBOUNDED_LEFT_OPEN,root2,0);
                    res->ints[0] = *int1;
                    res->ints[1] = *int2;
                    res->n = 2;
                    return res;
                }
                if (d == 0){
                    res->ints = (Interval*) malloc(sizeof(Interval));
                    Interval* int1;
                    int1 = input(UNBOUNDED,0,0);
                    res->ints = int1;
                    res->n = 1;
                    return res;
                }

            }
            if (iqt->a == 0)
            {
                float root;
                root = -iqt->c / iqt->b;

                res->ints = (Interval*) malloc(sizeof(Interval));
                Interval* int1;
                int1 = input(LEFT_UNBOUNDED_RIGHT_OPEN,0,root);
                res->ints = int1;
                res->n = 1;
                return res;
            }
        }
        case LESS_EQUAL:
        {
            if (iqt->a > 0)
            {
                if (d > 0)
                {
                    res->ints = (Interval*) malloc(sizeof(Interval));
                    Interval* int1;
                    int1 = input(CLOSED,root1,root2);
                    res->ints = int1;
                    res->n = 1;
                    return res;
                }
                if (d == 0){
                    res->ints = (Interval*) malloc(sizeof(Interval));
                    Interval* int1;
                    int1 = input(DEGENERATE,root1,root1);
                    res->ints = int1;
                    res->n = 1;
                    return res;
                }

            }
            if (iqt->a < 0)
            {
                if (d > 0)
                {
                    res->ints = (Interval*) malloc(sizeof(Interval) * 2);
                    Interval* int1;
                    Interval* int2;
                    int1 = input(LEFT_UNBOUNDED_RIGHT_CLOSED,0,root1);
                    int2 = input(RIGHT_UNBOUNDED_LEFT_CLOSED,root2,0);
                    res->ints[0] = *int1;
                    res->ints[1] = *int2;
                    res->n = 2;
                    return res;
                }
                if (d == 0){
                    res->ints = (Interval*) malloc(sizeof(Interval));
                    Interval* int1;
                    int1 = input(DEGENERATE,root1,root1);
                    res->ints = int1;
                    res->n = 1;
                    return res;
                }

            }
            if (iqt->a == 0)
            {
                float root;
                root = -iqt->c / iqt->b;

                res->ints = (Interval*) malloc(sizeof(Interval));
                Interval* int1;
                int1 = input(LEFT_UNBOUNDED_RIGHT_CLOSED,0,root);
                res->ints = int1;
                res->n = 1;
                return res;
            }
        }
        case GREATER_EQUAL:
        {
            if (iqt->a > 0)
            {
                if (d > 0)
                {
                    res->ints = (Interval*) malloc(sizeof(Interval) * 2);
                    Interval* int1;
                    Interval* int2;
//                    printf("%f\n",root1);
                    int1 = input(LEFT_UNBOUNDED_RIGHT_CLOSED,0,root1);
//                    printf("There\n");
  //                  output(int1);
                    int2 = input(RIGHT_UNBOUNDED_LEFT_CLOSED,root2,0);
                    res->ints[0] = *int1;
                    res->ints[1] = *int2;
                    res->n = 2;
                    return res;
                }
                if (d == 0){
                    res->ints = (Interval*) malloc(sizeof(Interval));
                    Interval* int1;
                    int1 = input(DEGENERATE,root1,root1);
                    res->ints = int1;
                    res->n = 1;
                    return res;
                }

            }
            if (iqt->a < 0)
            {
                if (d > 0)
                {
                    res->ints = (Interval*) malloc(sizeof(Interval));
                    Interval* int1;
                    int1 = input(CLOSED,root1,root2);
                    res->ints = int1;
                    res->n = 1;
                    return res;
                }
                if (d == 0){
                    res->ints = (Interval*) malloc(sizeof(Interval));
                    Interval* int1;
                    int1 = input(DEGENERATE,root1,root1);
                    res->ints = int1;
                    res->n = 1;
                    return res;
                }

            }
            if (iqt->a == 0)
            {
                float root;
                root = -iqt->c / iqt->b;

                res->ints = (Interval*) malloc(sizeof(Interval));
                Interval* int1;
                int1 = input(RIGHT_UNBOUNDED_LEFT_CLOSED,root,0);
                res->ints = int1;
                res->n = 1;
                return res;
            }
        }
        case EQUAL:
        {
            if (iqt->a == 0)
            {
                float root;
                root = -iqt->c / iqt->b;
                res->ints = (Interval*) malloc(sizeof(Interval));
                Interval* int1;
                int1 = input(DEGENERATE,root,root);
                res->ints = int1;
                res->n = 1;
                return res;
            }
            if (d > 0)
            {
                res->ints = (Interval*) malloc(sizeof(Interval));
                Interval* int1;
                Interval* int2;
                int1 = input(DEGENERATE,root1,root1);
                int2 = input(DEGENERATE,root2,root2);
                res->ints[0] = *int1;
                res->ints[1] = *int2;
                res->n = 2;
                return res;
            }
            if (d == 0)
            {
                res->ints = (Interval*) malloc(sizeof(Interval));
                Interval* int1;
                int1 = input(DEGENERATE,root1,root1);
                res->ints = int1;
                res->n = 1;
                return res;
            }


        }
        case NOT_EQUAL:
        {
            if (iqt->a == 0)
            {
                float root;
                root = -iqt->c / iqt->b;
                res->ints = (Interval*) malloc(sizeof(Interval) * 2);
                Interval* int1;
                Interval* int2;
                int1 = input(LEFT_UNBOUNDED_RIGHT_OPEN,0,root);
                int2 = input(RIGHT_UNBOUNDED_LEFT_OPEN,root,0);
                res->ints[0] = *int1;
                res->ints[1] = *int2;
                res->n = 2;
                return res;
            }
            if (d > 0)
            {
                res->ints = (Interval*) malloc(sizeof(Interval) * 3);
                Interval* int1;
                Interval* int2;
                Interval* int3;
                int1 = input(LEFT_UNBOUNDED_RIGHT_OPEN,0,root1);
                int2 = input(OPEN,root1,root2);
                int3 = input(RIGHT_UNBOUNDED_LEFT_OPEN,root2,0);
                res->ints[0] = *int1;
                res->ints[1] = *int2;
                res->ints[2] = *int3;
                res->n = 3;
                return res;
            }
            if (d == 0)
            {
                res->ints = (Interval*) malloc(sizeof(Interval) * 2);
                Interval* int1;
                Interval* int2;
                int1 = input(LEFT_UNBOUNDED_RIGHT_OPEN,0,root1);
                int2 = input(RIGHT_UNBOUNDED_LEFT_OPEN,root1,0);
                res->ints[0] = *int1;
                res->ints[1] = *int2;
                res->n = 2;
                return res;
            }
        }

    }

}


//функція знаходження розв`язку системи квадратних нерівностей
//знаходимо розв`язок кожного та шукаємо їхній перетин
SetIntervals* find_system_decision(SetIntervals* ints1, SetIntervals* ints2)
{
    SetIntervals* res_set = (SetIntervals*) malloc(sizeof(SetIntervals));
    res_set->ints = (Interval*) malloc(sizeof(Interval) * 2);
    res_set = set_add(ints1,ints2);
    return res_set;
}

SqIqualty* input_koef(float a,float b,float c,enum iq_type type_iq)
{
    SqIqualty* new_iq = (SqIqualty*) malloc(sizeof(SqIqualty));
    new_iq->a = a;
    new_iq->b = b;
    new_iq->c = c;
    new_iq->type = type_iq;
    return new_iq;
}


SqIqualty* input_system(int n)
{
    SqIqualty* new_set = (SqIqualty*) malloc(sizeof(SqIqualty) * n);
    for (int i = 0;i <= n-122;i++)
    {
        float a,b,c;
        int tp;
        int count = 0;
        SqIqualty* new_iq = (SqIqualty*) malloc(sizeof(SqIqualty));
        printf("a->\n");
        scanf("%f",&a);
        printf("b->\n");
        scanf("%f",&b);
        printf("c->\n");
        scanf("%f",&c);
        printf("type->\n");
        scanf("%i",&tp);
        new_iq->a = a;
        new_iq->b = b;
        new_iq->c = c;
        new_iq->type = tp;
        new_set[count] = *new_iq;
        count += 1;
    }
    return new_set;
}
