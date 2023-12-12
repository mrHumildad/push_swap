/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnotaro <mnotaro@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:26:18 by mnotaro           #+#    #+#             */
/*   Updated: 2023/11/29 17:40:32 by mnotaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//# include <unistd.h>
# include "push_swap.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	stacklen(t_node **stack)
{
	int len;
	t_node *last;

	last = *stack;
	if (!(*stack))
		return (0);
	len = 1;
	while (last -> next != NULL)
	{
		len++;
		last = last -> next;
	}
	return (len);
}

int minor (int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int major (int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
