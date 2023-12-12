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
}

void	rra(t_node **a, int times)
{
	while (times--)
	{
		ft_putstr("rra\n");
		rev_rotate(a);
	}
}

void	rrb(t_node **b, int times)
{
	while (times--)
	{
		ft_putstr("rrb\n");
		rev_rotate(b);
	}
}

void	rrr(t_node **a, t_node **b, int times)
{
	while (times--)
	{
		ft_putstr("rrr\n");
		rev_rotate(a);
		rev_rotate(b);
	}
}
