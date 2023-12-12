#include "push_swap.h"

static void refresh_indexes(t_node **s)
{
    t_node *refresher;
    int     i;
    int     len;
    
    refresher = *s;
    i = 0;
    len = stacklen(s);
    while(refresher)
    {
        refresher -> rot = i;
        refresher -> rev = len -i;
        i++;
        refresher = refresher -> next;
    }
}

static void targeting(t_node **from, t_node **to)
{
    t_node *mover;
    t_node *target;
    int     t_value;

    mover = *from;
   // target = *to;
   printf("targeting %li\n", mover -> value);
    while (mover)
    {
        if (closestsmall(to, mover -> value) == mover -> value)
            t_value = getmax(to);
        else
            t_value = closestsmall(to, mover -> value);
        printf("target of  %li  is %d\n", mover -> value, t_value);
        target = getnode(to, t_value);
        mover -> target_rot = target -> rot;
        mover -> target_rev = target -> rev;
        mover -> price = minor((minor(major(mover -> rot, mover -> target_rot), major(mover -> rot, mover -> target_rot)), minor(mover -> rot + mover -> target_rev, mover -> rev + mover -> target_rot));
        mover = mover -> next;
    }
}

int price(t_node *mover)
{
    int price;
    int rr;
    int rrr;
    int ra_rrb;
    int rb_rra;

    rr = major(mover -> rot, mover -> target_rot);
    rrr = major(mover -> rev, mover -> target_rev));
    ra_rrb = mover -> rot + mover -> target_rev;
    rb_rra = mover -> rev + mover -> target_rot;
    price = minor(minor(rr, rrr), minor(ra_rrb, rb_rra));
}

static void analyze_stack(t_node **from, t_node **to)
{
    (void)to;
    /*t_node *mover;
    t_node *target;

    mover = *from;
    target = *to;*/
    refresh_indexes(from);
    printStack(*from, 'a');
    refresh_indexes(to);
    printStack(*to, 'b');

    targeting(from, to);
    printStack(*from, 'a');
}    

static void populate_b(t_node **a, t_node **b)
{
    //t_node  *best;
    
    //best = *a;
    pb(a, b);
    pb(a, b);
    
    /*while (*a)
    {
        analyze_stack(a, b);
        move(a, b);
    }*/
    analyze_stack(a, b);
}

void    turk_sort(t_node** a, t_node **b)
{
    populate_b(a, b);
}
