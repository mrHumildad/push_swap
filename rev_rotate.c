/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnotaro <mnotaro@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:34:55 by mnotaro           #+#    #+#             */
/*   Updated: 2023/11/29 17:43:23 by mnotaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void rev_rotate (t_node **stack)
{
	t_node *old_head;
	t_node *new_last;
	t_node *old_last;

	if (stacklen(stack) < 2)
		return ;
	old_head = (*stack);
	old_last = findlast(stack);
	while ((*stack) -> next -> next != NULL)
		*stack = (*stack) -> next;
	new_last = *stack;
	new_last -> next = NULL;
	old_last -> next = old_head;
	(*stack) = old_last;
}*/
t_node	*before_bottom(t_node *stack)
{
	while (stack && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}
static void	rev_rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*tail;
	t_node	*new_tail;

	tail = findlast(stack);
	new_tail = before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	new_tail->next = NULL;
}

void	rra(t_node **a, int times)
{
	while (times > 0)
	{
		ft_putstr("rra\n");
		rev_rotate(a);
		times--;
	}
}

void	rrb(t_node **b, int times)
{
	while (times > 0)
	{
		ft_putstr("rrb\n");
		rev_rotate(b);
		times--;
	}
}

void	rrr(t_node **a, t_node **b, int times)
{
	while (times > 0)
	{
		ft_putstr("rrr\n");
		rev_rotate(a);
		rev_rotate(b);
		times--;
	}
}
