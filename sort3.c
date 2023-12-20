#include "push_swap.h"

void sort3(t_node **a)
{
//	printf("sorting 3\n");
	int primero = ((*a) -> value);
	int segundo = ((*a) -> next -> value);
	int tercero = ((*a) -> next -> next -> value);
	printf("HOLA\n");
	//if (((*a) -> value) > ((*a) -> next) -> value && )
	if (primero == getmin(a) && segundo == getmax(a))
	{
		rra(a, 1);
		sa(a);
	}
	else if (getmin(a) == segundo && getmax(a) == tercero)
		sa(a);	
	else if (getmin(a) == tercero && getmax(a) == segundo)
		rra(a, 1);
	else if (getmin(a) == segundo && getmax(a) == primero)
		ra(a, 1);
	else if (getmin(a) == tercero && getmax(a) == primero)
	{
		ra(a, 1);
		sa(a);
	}
//	printStack(*a, 'a'); 
}