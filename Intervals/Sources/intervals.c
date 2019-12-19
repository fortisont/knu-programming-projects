#include "intervals.h"

//функція виводу інтервалів
void output(Interval* inter)
{
    if (inter->interval_type == EMPTY)
    {
        printf("empty interval\n");
    }
    if (inter->interval_type == DEGENERATE)
    {
        inter->b = 0;
        printf("{%f} - single point\n",inter->a);
    }
    if (inter->interval_type == OPEN)
    {
        printf("(%f,%f)\n",inter->a,inter->b);
    }
    if (inter->interval_type == CLOSED)
    {
        printf("[%f,%f]\n",inter->a,inter->b);
    }
    if (inter->interval_type == LEFT_OPEN)
    {
        printf("(%f,%f]\n",inter->a,inter->b);
    }
    if (inter->interval_type == RIGHT_OPEN)
    {
        printf("[%f,%f)\n",inter->a,inter->b);
    }
    if (inter->interval_type == LEFT_UNBOUNDED_RIGHT_OPEN)
    {
        printf("(-inf,%f)\n",inter->b);
    }
    if (inter->interval_type == LEFT_UNBOUNDED_RIGHT_CLOSED)
    {
        printf("(-inf,%f]\n",inter->b);
    }
    if (inter->interval_type == RIGHT_UNBOUNDED_LEFT_OPEN)
    {
        printf("(%f,+inf)\n",inter->a);
    }
    if (inter->interval_type == RIGHT_UNBOUNDED_LEFT_CLOSED)
    {
        printf("[%f,+inf)\n",inter->a);
    }
    if (inter->interval_type == UNBOUNDED)
    {
        printf("(-inf,+inf)\n");
    }

}

//функція вводу новго інтервалу
Interval* input(enum Type int_type,float a, float b)
{
    Interval* new_inter = (Interval*) malloc (sizeof(Interval));
    new_inter->interval_type = int_type;
    new_inter->a = a;
    new_inter->b = b;

    return new_inter;
}

//функція визначення типу інтервала при об`єднанні
enum Type int_type(enum Type type_1,enum Type type_2)
{
    enum Type res;
    switch(type_1)
    {
        case OPEN:
        {
            if (type_2 == UNBOUNDED)
            {
                res = UNBOUNDED;
            }
            if (type_2 == EMPTY || type_2 == RIGHT_OPEN)
            {
                res = OPEN;
            }

            if (type_2 == CLOSED || type_2 == LEFT_OPEN)
            {
                res = LEFT_OPEN;
            }
            if (type_2 == RIGHT_UNBOUNDED_LEFT_OPEN || type_2 == RIGHT_UNBOUNDED_LEFT_CLOSED)
            {
                res = RIGHT_UNBOUNDED_LEFT_OPEN;
            }
            if (type_2 == LEFT_UNBOUNDED_RIGHT_OPEN)
            {
                res = LEFT_UNBOUNDED_RIGHT_OPEN;
            }
            if (type_2 == LEFT_UNBOUNDED_RIGHT_CLOSED)
            {
                res = LEFT_UNBOUNDED_RIGHT_CLOSED;
            }
        }return res;

        case CLOSED:
        {
            if (type_2 == UNBOUNDED)
            {
                res = UNBOUNDED;
            }
            if (type_2 == EMPTY || type_2 == LEFT_OPEN)
            {
                res = CLOSED;
            }
            if (type_2 == OPEN || type_2 == RIGHT_OPEN)
            {
                res = RIGHT_OPEN;
            }
            if (type_2 == RIGHT_UNBOUNDED_LEFT_OPEN || type_2 == RIGHT_UNBOUNDED_LEFT_CLOSED)
            {
                res = RIGHT_UNBOUNDED_LEFT_CLOSED;
            }
            if (type_2 == LEFT_UNBOUNDED_RIGHT_OPEN)
            {
                res = LEFT_UNBOUNDED_RIGHT_OPEN;
            }
            if (type_2 == LEFT_UNBOUNDED_RIGHT_CLOSED)
            {
                res = LEFT_UNBOUNDED_RIGHT_CLOSED;
            }
        } return res;
        case LEFT_UNBOUNDED_RIGHT_OPEN:
        {
            if (type_2 == EMPTY)
            {
                res = LEFT_UNBOUNDED_RIGHT_OPEN;
            }
            if (type_2 == UNBOUNDED)
            {
                res = UNBOUNDED;
            }
            if (type_2 == OPEN || type_2 == RIGHT_OPEN)
            {
                res = LEFT_UNBOUNDED_RIGHT_OPEN;

            }
            if (type_2 == CLOSED || type_2 == LEFT_OPEN)
            {
                res = LEFT_UNBOUNDED_RIGHT_CLOSED;

            }
            if (type_2 == LEFT_UNBOUNDED_RIGHT_OPEN)
            {
                res = LEFT_UNBOUNDED_RIGHT_OPEN;

            }
            if (type_2 == LEFT_UNBOUNDED_RIGHT_CLOSED)
            {
                res = LEFT_UNBOUNDED_RIGHT_CLOSED;

            }
            if (type_2 == RIGHT_UNBOUNDED_LEFT_OPEN|| type_2 == RIGHT_UNBOUNDED_LEFT_CLOSED)
            {
                res = UNBOUNDED;

            }
        }return res;
        case LEFT_UNBOUNDED_RIGHT_CLOSED:
        {
            if (type_2 == EMPTY)
            {
                res = LEFT_UNBOUNDED_RIGHT_OPEN;

            }
            if (type_2 == UNBOUNDED)
            {
                res = UNBOUNDED;

            }
            if (type_2 == OPEN || type_2 == RIGHT_OPEN)
            {
                res = LEFT_UNBOUNDED_RIGHT_OPEN;

            }
            if (type_2 == CLOSED || type_2 == LEFT_OPEN)
            {
                res = LEFT_UNBOUNDED_RIGHT_CLOSED;

            }
            if (type_2 == LEFT_UNBOUNDED_RIGHT_OPEN)
            {
                res = LEFT_UNBOUNDED_RIGHT_OPEN;

            }
            if (type_2 == LEFT_UNBOUNDED_RIGHT_CLOSED)
            {
                res = LEFT_UNBOUNDED_RIGHT_CLOSED;

            }
            if (type_2 == RIGHT_UNBOUNDED_LEFT_CLOSED )
            {
                res = UNBOUNDED;

            }
        }return res;
        case RIGHT_UNBOUNDED_LEFT_OPEN:
        {
            if (type_2 == UNBOUNDED)
            {
                res = UNBOUNDED;

            }
            else if (type_2 == CLOSED || type_2 == RIGHT_OPEN || type_2 == RIGHT_UNBOUNDED_LEFT_CLOSED)
            {
                res = RIGHT_UNBOUNDED_LEFT_CLOSED;

            }
            else
            {
                res = RIGHT_UNBOUNDED_LEFT_OPEN;

            }
        }return res;
        case RIGHT_UNBOUNDED_LEFT_CLOSED:
        {
            if (type_2 == UNBOUNDED)
            {
                res = UNBOUNDED;

            }
            else if (type_2 == OPEN || type_2 == LEFT_OPEN || type_2 == RIGHT_UNBOUNDED_LEFT_OPEN)
            {
                res = RIGHT_UNBOUNDED_LEFT_OPEN;

            }
            else if (type_2 == CLOSED || type_2 == RIGHT_OPEN || type_2 == RIGHT_UNBOUNDED_LEFT_CLOSED)
            {
                res = RIGHT_UNBOUNDED_LEFT_CLOSED;
            }

        }return res;
        case EMPTY:
        {
            res = type_2;
        }
        case LEFT_OPEN:
        {
            if (type_2 == EMPTY || type_2 == CLOSED)
            {
                res = LEFT_OPEN;
            }
            if (type_2 == UNBOUNDED)
            {
                res = UNBOUNDED;
            }
            if (type_2 == LEFT_UNBOUNDED_RIGHT_CLOSED)
            {
                res = LEFT_UNBOUNDED_RIGHT_CLOSED;
            }
            if (type_2 == LEFT_UNBOUNDED_RIGHT_OPEN)
            {
                res = LEFT_UNBOUNDED_RIGHT_OPEN;
            }
            if (type_2 == RIGHT_UNBOUNDED_LEFT_CLOSED)
            {
                res = RIGHT_UNBOUNDED_LEFT_OPEN;
            }
            if (type_2 == RIGHT_UNBOUNDED_LEFT_OPEN)
            {
                res = RIGHT_UNBOUNDED_LEFT_OPEN;
            }
            if (type_2 == RIGHT_OPEN || type_2 == OPEN)
            {
                res = OPEN;
            }
        }return res;
        case RIGHT_OPEN:
        {
            if (type_2 == EMPTY || type_2 == OPEN)
            {
                res = RIGHT_OPEN;
            }
            if (type_2 == UNBOUNDED)
            {
                res = UNBOUNDED;
            }
            if (type_2 == LEFT_OPEN || type_2 == CLOSED)
            {
                res = CLOSED;
            }
            if (type_2 == LEFT_UNBOUNDED_RIGHT_CLOSED)
            {
                res = LEFT_UNBOUNDED_RIGHT_CLOSED;
            }
            if (type_2 == LEFT_UNBOUNDED_RIGHT_OPEN)
            {
                res = LEFT_UNBOUNDED_RIGHT_OPEN;
            }
            if (type_2 == RIGHT_UNBOUNDED_LEFT_OPEN || type_2 == RIGHT_UNBOUNDED_LEFT_CLOSED)
            {
                res = RIGHT_UNBOUNDED_LEFT_CLOSED;
            }

        }return res;
        case UNBOUNDED: {
            res = UNBOUNDED;
        }return res;
    }

}

//функція визначення  об`єднання інтервалів
Interval* mult(Interval* inter_1,Interval* inter_2)
{
    float infinity = 999999999;
    if (inter_1->interval_type == LEFT_UNBOUNDED_RIGHT_OPEN || inter_1->interval_type == LEFT_UNBOUNDED_RIGHT_CLOSED )
    {
        inter_1->b = infinity;
    }
    if (inter_1->interval_type == RIGHT_UNBOUNDED_LEFT_CLOSED || inter_1->interval_type == RIGHT_UNBOUNDED_LEFT_OPEN )
    {
        inter_1->b = infinity;
    }
    if (inter_2->interval_type == LEFT_UNBOUNDED_RIGHT_OPEN || inter_2->interval_type == LEFT_UNBOUNDED_RIGHT_CLOSED )
    {
        inter_2->a = infinity;
    }
    if (inter_2->interval_type == RIGHT_UNBOUNDED_LEFT_CLOSED || inter_2->interval_type == RIGHT_UNBOUNDED_LEFT_OPEN )
    {
        inter_2->b = infinity;
    }
    if (inter_1->interval_type == UNBOUNDED)
    {
        inter_1->a = infinity;
        inter_1->b = infinity;
    }
    if (inter_2->interval_type == UNBOUNDED)
    {
        inter_2->a = infinity;
        inter_2->b = infinity;
    }
    enum Type left_part,right_part;
    Interval* res_inter = (Interval*) malloc(sizeof(Interval));
    if (inter_1->interval_type == DEGENERATE && inter_2->interval_type == DEGENERATE)
    {
        if (inter_1->a == inter_2->a)
        {
            res_inter->a = inter_1->a;
            res_inter->b = 0;
            res_inter->interval_type = DEGENERATE;
        }
        else{
            res_inter->a = 0;
            res_inter->b = 0;
            res_inter->interval_type = EMPTY;
        }
    }
    else{
        if (inter_1->b < inter_2->a)
        {
            Interval* ints = (Interval*) malloc(sizeof(Interval) * 2);
            ints[0] = *inter_1;
            ints[1] = *inter_2;
            return ints;
        }
        if (inter_1->a <= inter_2->a)
        {
            res_inter->a = inter_1->a;
            left_part = inter_1->interval_type;
        }
        else
        {
            res_inter->a = inter_2->a;
            left_part = inter_2->interval_type;
        }
        if (inter_1->b > inter_2->b)
        {
            res_inter->b = inter_1->b;
            right_part = inter_1->interval_type;
        }
        else
        {
            res_inter->b = inter_2->b;
            right_part = inter_2->interval_type;
        }
        if (inter_1->interval_type == inter_2->interval_type)
        {
            res_inter->interval_type = inter_1->interval_type;

        }
        else
        {
            res_inter->interval_type = int_type(left_part,right_part);

        }
    }
    return res_inter;

}

//функція часткового типу інтервала
//тобто задаємо інтервал та елемент a чи b  з нього
//функція визначає  відкритий чи закритий інтервал збоку цього елемента
enum Type part_type(char el,Interval* inter)
{
    enum Type res;
    if (el == 'a')
    {
        if (inter->interval_type == OPEN || inter->interval_type == LEFT_OPEN || inter->interval_type == RIGHT_UNBOUNDED_LEFT_OPEN)
        {
            res = OPEN;
        }
        if (inter->interval_type == CLOSED || inter->interval_type == RIGHT_OPEN || inter->interval_type == RIGHT_UNBOUNDED_LEFT_CLOSED)
        {
            res = CLOSED;
        }
        if (inter->interval_type == LEFT_UNBOUNDED_RIGHT_CLOSED || inter->interval_type == LEFT_UNBOUNDED_RIGHT_OPEN)
        {
            res = UNBOUNDED;
        }
    }
    if (el == 'b')
    {
        if (inter->interval_type == OPEN || inter->interval_type == RIGHT_OPEN || inter->interval_type == LEFT_UNBOUNDED_RIGHT_OPEN)
        {
            res = OPEN;
        }
        if (inter->interval_type == CLOSED || inter->interval_type == LEFT_OPEN || inter->interval_type == LEFT_UNBOUNDED_RIGHT_CLOSED)
        {
            res = CLOSED;
        }
        if (inter->interval_type == RIGHT_UNBOUNDED_LEFT_CLOSED || inter->interval_type == RIGHT_UNBOUNDED_LEFT_OPEN)
        {
            res = UNBOUNDED;
        }
    }
    return res;
}


//функції find_a та find_b визначають значення a і b для перетину інтервалів
int find_a(Interval* in1,Interval* in2)
{

    int res_a;
    int infinity = 999999999;
    if (in1->interval_type == LEFT_UNBOUNDED_RIGHT_CLOSED || in1->interval_type == LEFT_UNBOUNDED_RIGHT_OPEN)
    {
        in1->a = -infinity;

    }
    if (in1->a == in2->a)
    {
        res_a = in1->a;

    }
    else if (in1->a > in2->a)
    {
        res_a = in1->a;
    }
    else
    {

        res_a = in2->a;

    }
    return res_a;
}

int find_b(Interval* in1,Interval* in2)
{
    int res_b;
    int infinity = 999999999;
    if (in1->interval_type == RIGHT_UNBOUNDED_LEFT_CLOSED || in1->interval_type == RIGHT_UNBOUNDED_LEFT_OPEN)
    {
        in1->b = infinity;
    }
    if (in1->b == in2->b)
    {
        res_b = in1->b;
    }
    else if (in1->b > in2->b)
    {
        res_b = in2->b;
    }
    else
    {
        res_b = in1->b;
    }
    return res_b;
}

//функція значходження перетину
//спочатку перебір часкових випадків
//якщо жоден з часткових випадків не підходить
//то шукаємо за допомогою find_a,find_b значення a і b
//далі зназодимо часткові типи а і b за допомогою part_type
// за допомогою int_type знаходимо тип всього перетину
Interval* addition(Interval* inter_1, Interval* inter_2)
{
    enum Type tp_left,tp_right;
    if (inter_1 == inter_2)
    {
        return inter_1;
    }
    if (inter_1->interval_type == UNBOUNDED)
    {
        return inter_2;
    }
    if (inter_2->interval_type == UNBOUNDED)
    {
        return inter_1;
    }
    Interval* res_inter = (Interval*) malloc(sizeof(Interval));
    if (inter_1->interval_type == EMPTY || inter_2->interval_type == EMPTY)
    {
        res_inter->a = 0;
        res_inter->b = 0;
        res_inter->interval_type = EMPTY;
        return res_inter;
    }
    if (inter_1->b == inter_2->a )
    {
        enum Type t_a,t_b;
        t_a = part_type('a',inter_2);
        t_b = part_type('b',inter_1);
        if (t_a == CLOSED && t_b == CLOSED)
        {
            res_inter->a = inter_1->b;
            res_inter->b = inter_2->a;
            res_inter->interval_type = DEGENERATE;
            return res_inter;
        }

        res_inter->a = 0;
        res_inter->b = 0;
        res_inter->interval_type = EMPTY;

    }
    else {
        if (inter_1->b < inter_2->a)
        {

            res_inter->a = 0;
            res_inter->b = 0;
            res_inter->interval_type = EMPTY;
            return res_inter;
        }
        if (inter_1->interval_type == DEGENERATE)
        {
            if (inter_1->a >= inter_2->a && inter_1->a <= inter_2->b)
            {
                return inter_2;
            }

        }
        else{
            res_inter->a = find_a(inter_1, inter_2);
            res_inter->b = find_b(inter_1, inter_2);
            if (res_inter->a == inter_1->a && res_inter->a == inter_2->a)
            {
                if (inter_1->interval_type == inter_2->interval_type)
                {
                    res_inter->interval_type = inter_1->interval_type;
                }
                else{
                    res_inter->interval_type = OPEN;
                }
            }
            else if (res_inter->b == inter_1->b && res_inter->b == inter_2->b) {
                if (inter_1->interval_type == inter_2->interval_type) {
                    res_inter->interval_type = inter_1->interval_type;
                } else {
                    res_inter->interval_type = OPEN;
                }
            }else{
                if (res_inter->a == inter_1->a)
                {
                    tp_left = part_type('a',inter_1);

                }
                else{
                    tp_left = part_type('a',inter_2);
                }
                if (res_inter->b == inter_1->b)
                {
                    tp_right = part_type('b',inter_1);
                }
                else{
                    tp_right = part_type('b',inter_2);
                }
                res_inter->interval_type = int_type(tp_left,tp_right);
            }

        }
    }
    if (res_inter->b < res_inter->a)
    {
        res_inter->a = 0;
        res_inter->b = 0;
        res_inter->interval_type = EMPTY;
    }
    return res_inter;

}

//функція значходження різниці
//з перетину інтервалів знаходимо границі різниці інтервалів
//та об`єднуєм необхідні значення а,b залежно від значень
Interval* difference(Interval* inter_1, Interval* inter_2)
{
    enum Type pt_a2, pt_b1, pt_a1, pt_b2, pt_a0, pt_b0,res1, res2;
    Interval* intersect = (Interval*) malloc(sizeof(Interval));
    Interval* int1 = (Interval*) malloc(sizeof(Interval));
    Interval* int2 = (Interval*) malloc(sizeof(Interval));
    Interval* ints = (Interval*) malloc(sizeof(Interval)*2);
    intersect = addition(inter_1, inter_2);
    //частковий тип для а першого інтервалу
    pt_a1 = part_type('a',inter_1);
    //частковий тип для b першого інтервалу
    pt_b1 = part_type('b',inter_1);
    //частковий тип для а перетину інтервалів
    pt_b0 = part_type('a',intersect);
    //частковий тип для b перетину інтервалів
    pt_a0 = part_type('b',intersect);
    //частковий тип для а другого інтервалу
    pt_a2 = part_type('a',inter_2);
    //частковий тип для b другого інтервалу
    pt_b2 = part_type('b',inter_2);

    if (pt_a0 == OPEN)
    {
        pt_b1 = CLOSED;
    }
    else{
        pt_b1 = OPEN;
    }
    if (pt_b0 == OPEN)
    {
        pt_a1 = CLOSED;
    }
    else{
        pt_a1 = OPEN;
    }
    res1 = int_type(pt_a1, pt_b1);
    res2 = int_type(pt_a2, pt_b2);
    if (intersect->interval_type == EMPTY)
    {
        ints[0] = *inter_1;
        ints[1] = *inter_2;
        return ints;
    }
    if (inter_1->a == inter_2->a && pt_b0 == OPEN)
    {
        int1->a = inter_1->a;
        int1->b = inter_1->a;
        int1->interval_type = DEGENERATE;

        if (inter_1->b > inter_2->b)
        {
            int2->a = intersect->b;
            int2->b = inter_1->b;
            int2->interval_type = int_type(pt_b1,pt_a0);
        }
        if (inter_1->b < inter_2->b)
        {
            int2->a = intersect->b;
            int2->b = inter_2->b;
            int2->interval_type = int_type(pt_b2,pt_a0);

        }
        ints[0] = *int1;
        ints[1] = *int2;
        return ints;

    }
    if (inter_1->b == inter_2->b && pt_a0 == OPEN)
    {
        int2->a = inter_1->b;
        int2->b = inter_1->b;
        int2->interval_type = DEGENERATE;

        if (inter_1->a > inter_2->a)
        {
            int1->a = inter_2->a;
            int1->b = intersect->a;
            int1->interval_type = int_type(pt_a2,pt_b0);
        }
        if (inter_1->a < inter_2->a)
        {
            int1->a = inter_1->a;
            int1->b = intersect->a;
            int2->interval_type = int_type(pt_a1,pt_b0);
        }
        ints[0] = *int1;
        ints[1] = *int2;
        return ints;
    }

    if (inter_1->a > inter_2->a)
    {
        int1->a = inter_2->a;
        int1->b = inter_1->a;
        if (inter_1->b > inter_2->b)
        {
            int2->a = inter_2->b;
            int2->b = inter_1->b;
        }
        if (inter_1->b < inter_2->b)
        {
            int2->a = inter_1->b;
            int2->b = inter_2->b;
        }
    }
    else if (inter_1->a < inter_2->a) {
        int1->a = inter_1->a;
        int1->b = inter_2->a;
        if (inter_1->b > inter_2->b) {
            int2->a = inter_2->b;
            int2->b = inter_1->b;
        }
        if (inter_1->b < inter_2->b) {
            int2->a = inter_1->b;
            int2->b = inter_2->b;
        }
    }else{
        if (inter_1->b > inter_2->b)
        {
            int1->a = inter_2->b;
            int1->b = inter_1->b;
        }
        if (inter_1->b < inter_2->b)
        {
            int1->a = inter_1->b;
            int1->b = inter_2->b;
        }
    }
    int1->interval_type = int_type(res1, res2);
    int2->interval_type = int_type(res1, res2);
    ints[0] = *int1;
    ints[1] = *int2;
    return ints;


}

