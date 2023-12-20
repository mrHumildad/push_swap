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
		printf("node %d[%c] : %li	rot : %d	rev : %d	t_rot ; %d	t_rev :%d	price : %d\n", i, s, stack->value, stack->rot, stack->rev, stack->target_rot, stack->target_rev, stack -> price);
		i++;
		stack = stack->next;
	}
	//printf("node %d[%c] : %li\n\n", i, s, stack->value);
		printf("node %d[%c] : %li	rot : %d	rev : %d	t_rot ; %d	t_rev :%d	price : %d\n", i, s, stack->value, stack->rot, stack->rev, stack->target_rot, stack->target_rev, stack -> price);

}

int isnumber(char **str)
{
	int i;
	int s;

	s = 0;
	while (str[s])
	{
		if ((ft_strcmp(str[s], "" ) == 0) || str[s][0] == '\0')// || (ft_strcmp(str[s], "+" ) == 0) || (ft_strcmp(str[s], "-" ) == 0))
			return (0);
		i = 0;
		if (str[s][0]== '+' || str[s][0] == '-')
			i++;
		while (str[s][i++] != '\0')
		{
			if (str[s][i] < 48 || str[s][i] > 57)
				return (0);
		}	
	}
	return (1);
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

void buildstack(t_node **a, char **splitted)
{
	long	n;
	int		i;

	i = 0;
	while (splitted[i])
	{
		n = ft_atol(splitted[i]);
		add2stack(a, n);
		i++;
	}
	//printStack(*a, 'a');
}

/*void freeStack(t_node **s)
{
	t_node	*following;

	while (*s)
	{
		following = (*s) -> next;
		        long            value;
        free((*s) -> pos);
        free((*s) -> top);
        free((*s) -> rot);
        free((*s) -> rev);
        free((*s) -> target_rev);
        free((*s) -> target_rot);
        free((*s) -> price);
        free((*s) -> next);
		free(*s);
		*s = following;
	}
}*/

void	freeStack(t_node **stack)
{
	t_node	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int ft_exit(t_node **a, t_node **b, int err)
{
	if (err < 0)
		printf("Error\n");
	freeStack(a);
	freeStack(b);
	return (0);
}

int main(int ac, char **av)
{
	t_node *a;
	t_node *b;
	int i;
	char	**splitted;

	a = (t_node *)malloc(sizeof(t_node));
	b = (t_node *)malloc(sizeof(t_node));
	a = NULL;
	b = NULL;
	i = 1;
	if (ac < 3)// || (ac == 2 && av[1][0] == NULL))
		return(0);
	while (i < ac)
    {
        splitted = ft_split(av[i], ' ');
		if (isnumber(splitted) == 0)
		{
			freeall(splitted);
			return(ft_exit(&a, &b, -1));
		}		
		buildstack(&a, splitted);
        i++;
		freeall(splitted);
    }
	printf("INPUT:\n");
	printStack(a, 'a');
	if (checkstack(&a) < 1)
		return(ft_exit(&a, &b, checkstack(&a)));
	if ((stacklen(&a) == 2) )
	{
		//if ((a -> value) > (a -> next -> value))
		sa(&a);
	}
	if (stacklen(&a) == 3)
		sort3(&a);
	if (stacklen(&a) > 3)
		turk_sort(&a, &b);
	printf("OUTPUT:\n");
	printStack(a, 'a');
	return(ft_exit(&a, &b, 1));
	//freeStack(&a);
	//freeStack(&b);
	return(0);
}
