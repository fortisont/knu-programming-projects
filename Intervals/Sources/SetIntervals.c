#include "SetIntervals.h"

//цикл для зображення массиву інтервалів
void print_set(SetIntervals* set)
{
    Interval* tmp1;
    for(tmp1 = set->ints; tmp1 <= &(set -> ints[set->n-1]);tmp1++ )
    {
        output(tmp1);
    }
}

//спроба реалізувати видалення з масиву повторювані інтервали
//функція не працює коректно
void rmdup(SetIntervals* set)
{
    Interval *current ;
    Interval *end = set->ints + set->n - 1;

    for ( current = set->ints + 1; set->ints < end; set->ints++, current = set->ints + 1 )
    {
        while ( current <= end )
        {
            printf("Curr\n");
            output(current);
            printf("One\n");
            output(set->ints);
            if ( &current == &set->ints )
            {
                *current = *end--;
            }
            else
            {
                current++;
            }
        }
    }
}


//функція визначення  об`єднання масивів інтервалів
//ідея полягала у визначенні об`єднання кожного інтервала першого массиву з кожним з другого
//потім видалення з отриманого массиву різниці кожних двох інтервалі
//і отримання кінцевого об`єднання
SetIntervals* set_mult(SetIntervals* ints1,SetIntervals* ints2)
{
    int count = 0;
    SetIntervals* mult_set = (SetIntervals*) malloc(sizeof(SetIntervals));
    mult_set->ints = (Interval*) malloc(sizeof(Interval) * 2 * ints1->n);
    SetIntervals* sort_mult_set = (SetIntervals*) malloc(sizeof(SetIntervals));
    sort_mult_set->ints = (Interval*) malloc(sizeof(Interval) * 2 *mult_set->n);
    Interval* tmp1;
    Interval* tmp2;
    Interval* mult_tmp;
    Interval* add_tmp;
    for (tmp1 = ints1->ints; tmp1 <= &(ints1 -> ints[ints1->n - 1]);tmp1++)
    {
        for (tmp2 = ints2->ints; tmp2 <= &ints2 -> ints[ints2->n-1];tmp2++)
        {

            add_tmp = addition(tmp1,tmp2);
            mult_tmp = mult(tmp1,tmp2);
            if (add_tmp->interval_type == EMPTY)
            {
                mult_set->ints[count] = *tmp1;
                mult_set->ints[count+1] = *tmp2;
                count +=2;
            }
            else
            {
                mult_set->ints[count] = *mult_tmp;
                count +=1;
            }
    }
    }
    mult_set->n = count;
    rmdup(mult_set);
    SetIntervals* res_set = (SetIntervals*) malloc(sizeof(SetIntervals));
    res_set->ints = (Interval*) malloc(sizeof(Interval) * ints1->n);
    Interval* tmp3;
    Interval* tmp4;
    int count2 = 0;
    Interval* dif;
    Interval* res;
    dif = mult(&mult_set->ints[0],&mult_set->ints[1]);
    for (tmp4 = ints1->ints; tmp4 <= &(ints1 -> ints[ints1->n - 1]);tmp4++)
    {
        if (tmp4 == &ints1->ints[ints1->n-1])
        {
            break;
        }
        for (tmp3 = mult_set->ints; tmp3 <= &(mult_set -> ints[mult_set->n - 1]);tmp3++)
        {

            dif = difference(tmp3,tmp4);
            res = mult(tmp4,dif);
            res_set->ints[count2] = *res;
            count2 += 1;
        }


    }

    res_set->n = count2;

    return res_set;

}


//Функція знаходження перетину масивів інтервалів
//Аналогічно знаходимо перетини кожного інтервала першого массиву з кожним з другого
//якщо хоча б один з перетинів порожній інтервал, то перетин масивів теж порожній інтервал
SetIntervals* set_add(SetIntervals* ints1, SetIntervals* ints2)
{
    int count = 0;
    Interval* tmp1;
    Interval* tmp2;
    SetIntervals* add_set = (SetIntervals*) malloc(sizeof(SetIntervals));
    add_set->ints = (Interval*) malloc(sizeof(Interval) * ints1->n);
    Interval* addition_tmp;
    for (tmp1 = ints1->ints; tmp1 <= &(ints1 -> ints[ints1->n - 1]);tmp1++ )
    {

        for (tmp2 = ints2->ints; tmp2 <= &ints2 -> ints[ints2->n-1];tmp2++)
        {



            addition_tmp = addition(tmp1,tmp2);
            if (addition_tmp->interval_type == EMPTY)
            {
                add_set->ints->a = 0;
                add_set->ints->b = 0;
                add_set->ints->interval_type = EMPTY;
                break;
            }
            add_set->ints[count] = *addition_tmp;
            count += 1;
            break;


        }
    }
    add_set->n = count;

    return add_set;

}


//Функція знаходження різниці масивів інтервалів
SetIntervals* set_dif(SetIntervals* ints1, SetIntervals* ints2)
{
    int count = 0;
    Interval* tmp1;
    Interval* tmp2;
    SetIntervals* dif_tmp = (SetIntervals*) malloc(sizeof(SetIntervals));
    dif_tmp->ints = (Interval*) malloc(sizeof(Interval) * 2 * ints1->n);
    for (tmp1 = ints1->ints; tmp1 <= &(ints1 -> ints[ints1->n - 1]);tmp1++) {
        for (tmp2 = ints2->ints; tmp2 <= &ints2->ints[ints2->n - 1]; tmp2++) {

            printf("El1->\n");
            output(tmp1);
            printf("El2->\n");
            output(tmp2);
            Interval* add;
            Interval* dif;
            printf("add ->\n");
            add = addition(tmp1,tmp2);
            output(add);
            printf("dif ->\n");
            dif = difference(tmp1, add);
            output(dif);
            dif_tmp->ints[count] = *dif;
            count += 1;

        }
    }
    dif_tmp->n = count;
    return dif_tmp;
}




