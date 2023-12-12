/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnotaro <mnotaro@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:05:07 by mnotaro           #+#    #+#             */
/*   Updated: 2023/11/28 19:40:47 by mnotaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include <unistd.h>
static	void swap (t_node **stack)
{
	t_node *tmp;
	void *p3;
	if (!*stack || (*stack)->next == NULL)
	{
		printf("\nerror\n");
		return ;
	}
//	tmp = malloc(sizeof(t_node));
//	if (!tmp)
//		return ;
	tmp = *stack;
//	printStack(tmp, 'n');
//	printStack(*stack, 's');
//	printf("stak -> next : %p\n", (*stack) ->next);
//	printf("tmp -> next : %p\n", tmp ->next);
	*stack = (*stack) -> next;
	p3 = (*stack) -> next;
	(*stack) -> next = tmp;
	tmp -> next = p3;
//	free(tmp);
}

void	sa(t_node **a)
{
	swap(a);
	ft_putstr("sa\n");
}

void	sb(t_node **b)
{
	swap(b);
	ft_putstr("sb\n");
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	ft_putstr("ss\n");
}
