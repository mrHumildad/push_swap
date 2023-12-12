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

/*int containssint(t_node **a)
{
    t_node *checker;

    checker = *a;
    while (checker)
    {
        if ((checker -> value) > 2147483647 || (checker -> value) < -2147483648)
        {
            printf("%li is not int!", checker -> value);
            return (0);
        checker = checker -> next;
        }
    }
    printf("all values in stack are int");
    return (1);
}*/

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
                {
                    printf("%d is = to %d\n", (int)home ->value, (int)target -> value);
;                   return (1);
                }
                //else
                 //   printf("%d is != to %d\n", (int)home ->value, (int)target -> value);
                target = target -> next;
        }
        home = home -> next;
    }
    return (0);
}

int checkstack(t_node **a)
{
	if (!*a || issorted(*a) || isrepeated(a)/* || containssint(a)*/)
        return (0);
    return (1);
}
