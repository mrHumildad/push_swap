/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnotaro <mnotaro@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:06:19 by mnotaro           #+#    #+#             */
/*   Updated: 2023/11/29 17:44:22 by mnotaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*new_head;
	t_node	*old_end;

	if (!stack || stacklen(stack) < 2)
		return ;
	new_head = (*stack) ->next;
	old_end = findlast(stack);
	old_end -> next = (*stack);
	(*stack) -> next = NULL;
	*stack = new_head;
}

void	ra(t_node **a, int times)
{
	while (times--)
	{
		ft_putstr("ra\n");
		rotate(a);
	}

}
void	rb(t_node **b, int times)
{
	while (times--)
	{
		ft_putstr("rb\n");
		rotate(b);
	}
}

void	rr(t_node **a, t_node**b, int times)
{
	while (times--)
	{
		ft_putstr("rr\n");
		rotate(a);
		rotate(b);
	}
}
