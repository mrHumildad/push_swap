/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnotaro <mnotaro@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:23:28 by mnotaro           #+#    #+#             */
/*   Updated: 2023/12/02 14:23:31 by mnotaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>                             //TEST ONLY!!!
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
        long             value;
        char            *pos;
        int             top;
        int             rot;
        int             rev;
        int             target_rev;
        int             target_rot;
        int             price;
        struct s_node   *next;
}                               t_node;

//                      only testing
//
void    printStack(t_node *stack, char s);
	
//                      moves
//
void    sa(t_node **a);
void    sb(t_node **a);
void    ss(t_node **a, t_node **b);

void    pa(t_node **a, t_node **b);
void    pb(t_node **a, t_node **b);

void    ra(t_node **a);
void    rb(t_node **b);
void    rr(t_node **a, t_node **b);

void    rra(t_node **a);
void    rrb(t_node **b);
void    rrr(t_node **a, t_node **b);

//                      sorting
//
void    sort3(t_node **a);
void    turk_sort(t_node **a, t_node **b);

//                      utils
//
void    ft_putstr(char *str);
t_node  *findlast(t_node **stack);
int     stacklen(t_node **stack);
int	checkstack(t_node **stack);
int     issorted(t_node *stack);
int    getmax(t_node **a);
int    getmin(t_node **a);
int     getpos(t_node **a, long int n);
int     closestsmall(t_node **b, int n);
int     closestbig(t_node **b, int n);
t_node *getnode(t_node **a, long int n);
int minor (int a, int b);
int major (int a, int b);

#endif