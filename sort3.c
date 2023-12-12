#include "push_swap.h"

void sort3(t_node **a)
{
	printf("sorting 3\n");
	int primero = ((*a) -> value);
	int segundo = ((*a) -> next -> value);
	int tercero = ((*a) -> next -> next -> value);
	
	//if (((*a) -> value) > ((*a) -> next) -> value && )
	if (primero == getmin(a) && segundo == getmax(a))
	{
		rra(a);
		sa(a);
	}
	else if (getmin(a) == segundo && getmax(a) == tercero)
		sa(a);	
	else if (getmin(a) == tercero && getmax(a) == segundo)
		rra(a);
	else if (getmin(a) == segundo && getmax(a) == primero)
		ra(a);
	else if (getmin(a) == tercero && getmax(a) == primero)
	{
		ra(a);
		sa(a);
	}
	printStack(*a, 'a'); 
}

/*void sort4or5(t_node **a)
{
	

}*/