/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnotaro <mnotaro@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:43:22 by mnotaro           #+#    #+#             */
/*   Updated: 2023/11/29 16:00:05 by mnotaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **from, t_node **to)
{
	t_node *from_head;

	if (!*from)
		return ;
	from_head = (*from) -> next;
	(*from) -> next = *to;
	*to = *from;
	*from = from_head;
}

void	pa(t_node **a, t_node **b, int times)
{
	while (times > 0)
	{
		ft_putstr("pa\n");
		push(b, a);
		times--;
	}
}

void	pb(t_node **a, t_node **b, int times)
{	
	while (times > 0)
	{
		ft_putstr("pb\n");
		push(a, b);
		times--;
	}
}
