/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnotaro <mnotaro@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:32:49 by mnotaro           #+#    #+#             */
/*   Updated: 2023/12/02 13:59:24 by mnotaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int issorted(t_node *stack)
{
	int n;

	n = stack -> value;
	while (stack -> next != NULL)
	{
		stack = stack ->next;
		if (stack -> value < n)
			return (0);
		n = stack -> value;
	}
	if (stack -> value < n)
		return (0);
	return (1);
}

void printStack(t_node *stack, char s)
{
	int i = 1;

	printf("-----------STACK %c[len : %d]---------------\n", s, stacklen(&stack));
	if (stack == NULL || !stack)
	{
		printf("stack %c is empty\n", s);
		return ;
	}
	if (issorted(stack))
		printf("stack %c is sorted!!\n", s);
	while (stack->next)
	{
		printf("node %d[%c] : %li	rot : %d	rev : %d	t_rot ; %d	t_rev :%d\n", i, s, stack->value, stack->rot, stack->rev, stack->target_rot, stack->target_rev);
		i++;
		stack = stack->next;
	}
	//printf("node %d[%c] : %li\n\n", i, s, stack->value);
	printf("node %d[%c] : %li	rot : %d	rev : %d	t_rot ; %d	t_rev :%d\n", i, s, stack->value, stack->rot, stack->rev, stack->target_rot, stack->target_rev);

}

static long	ft_atol(const char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return ((long)(num * sign));
}

t_node *findlast(t_node **stack)
{
	t_node *last;

	if (!(*stack))
		return (NULL);
	last = *stack;
	while (last -> next != NULL)
	{
		last = last -> next;
	}
	return(last);
}
t_node *newnode(long n)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->value = n;
	new -> pos = "";
	return(new);
}

void add2stack(t_node **stack, long int n)
{
	t_node *new;
	t_node *last;

	if (stack == NULL)
		return;
	new = newnode(n);
	if (!new)
		return;
	if (!*stack)
		*stack = new;
	else
	{
		last = findlast(stack);
		last->next = new;
	}
}

void buildstack(t_node **a, char **av, int ac)
{
	long	n;
	int		i;

	i = 1;
//	n = 0;
//	printf("buildstack %d elements\n", (ac - 1));
	while (i < ac)
	{
		n = ft_atol(av[i]);
//		printf("building stack step %d : number %i\n", i, (int)n);
		add2stack(a, n);
		i++;
	}
}


int main(int ac, char **av)
{
	t_node *a;
	t_node *b;

	a = NULL;
	b = NULL;
	if (ac == 1)// || (ac == 2 && av[1][0] == NULL))
		return(0);
	//ac--;
	/*if (ac == 1)

	  av = ft_split(av[1], ' ');
	  ac = countargs*/
//	printf("main\n");
	buildstack(&a, av, ac);
//	buildstack(&b, av, ac);
	if (checkstack(&a) == 0)
	{
		printf("STACK CHECK KO\n");
		return (0);
	}
	printStack(a, 'a');
	printStack(b, 'b');
	//getmax(&a);
	//getmin(&a);
	/*if (!checkstack(&a))
	{
		free(&a);
		return (0);
	}*/

	if (ac == 3)
	{
		//printf("a -> value : %d", a -> value);
		if ((a -> value) > (a -> next -> value))
			sa(&a);
		printStack(a, 'a');
	}
	if (ac == 4)
	{
		sort3(&a);
		//printf("la posicion de 2 es: %d", getpos(&a, 2));
	}
	if (ac > 4)
	{
		turk_sort(&a, &b);
	}
	/*int cs = closestsmall(&a, 5);
	int cb = closestbig(&a, 5);
	printf("closestsmall of 5 in a is : %d\n", cs);
	printf("closestbig of 5 in a is : %d\n", cb);
*/
//	sa(&a);
//	printStack(a, 'a');
//	rr(&a, &b);

//	printStack(a, 'a');
//	printStack(b, 'b');
	return(0);
}
