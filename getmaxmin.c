#include "push_swap.h"

int    getmax(t_node **a)
{
    t_node      *checker;
    int         max;

/*     if (!*a)
        return (NULL); */
    checker = *a;
    max = checker -> value;
    while (checker)
    {
        if (checker -> value > max)
        {
            max = checker -> value;
        }
        checker = checker -> next;
    }
 //   printf("max = %d\n", max);

    return (max);
}

int    getmin(t_node **a)
{
    t_node      *checker;
    int         min;

/*     if (!*a)
        return (NULL); */
    checker = *a;
    min = checker -> value;
    while (checker)
    {
        if (checker -> value < min)
        {
            min = checker -> value;
        }
        checker = checker -> next;
    }
      //  printf("min = %d", min);
    return (min);
}

int     getnextmin(t_node **a, int oldmin)
{
    t_node      *checker;
    int         nextmin;

    checker = *a;
    if (checker -> value == oldmin)
        checker = checker -> next;
    nextmin = checker -> value; 
    while (checker)
    {
        if (checker -> value < nextmin)
        {
            nextmin = checker -> value;
        }
        checker = checker -> next;
    }
    return (nextmin);
}
