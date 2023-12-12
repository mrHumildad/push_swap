#include "push_swap.h"

int closestsmall(t_node **b, int n)
{
    int cs;
    long diff;
    t_node  *finder;

    cs = n;
    finder = *b;
    diff = INT_MAX;
    while(finder)
    {
        if (finder -> value < n && (n - (finder -> value)) < diff)
        {
            cs = finder -> value;
            diff = n - (finder -> value);
        }
        finder = finder -> next;
    }
    return (cs);
}
int closestbig(t_node **b, int n)
{
    int cb;
    long diff;
    t_node  *finder;

    cb = n;
    finder = *b;
    diff = INT_MAX ;//* 2 + 1;
    while(finder)
    {
        printf("closestbig in the while, %li\n", finder -> value);
        if (finder -> value > n && ((finder -> value) - n) < diff)
        {
            printf("closestbig in the if\n");
            cb = finder -> value;
            printf("cb = %d\n", cb);
            diff = (finder -> value) - n;
            printf("diff = %li\n", diff);
        }
        finder = finder -> next;
    }
    return (cb);
}

int getpos(t_node **a, long int n)
{
	int 	pos;
	t_node	*finder;

	pos = 0;
	finder = *a;
	while (finder -> value != n)
	{
		finder = finder ->next;
		pos++;
	}
	return (pos);
}

t_node *getnode(t_node **a, long int n)
{
	int 	pos;
	t_node	*finder;

	pos = 1;
	finder = *a;
	while (finder -> value != n)
	{
		finder = finder ->next;
		pos++;
	}
	return (finder);
}

