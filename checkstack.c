/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnotaro <mnotaro@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:59:57 by mnotaro           #+#    #+#             */
/*   Updated: 2023/12/02 14:02:23 by mnotaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int isrepeated(t_node **a)
{
    t_node *home;
    t_node *target;

    home = *a;
    while (home -> next != NULL)
    {
        target = home -> next;
        while (target)
        {
                if (home -> value == target -> value)
                   return (1);
                target = target -> next;
        }
        home = home -> next;
    }
    return (0);
}

int checkstack(t_node **a)
{
	if (!*a || isrepeated(a))
        return (-1);
    if (issorted(*a))
        return (0);
    return (1);
}
