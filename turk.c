#include "push_swap.h"

int pricing(t_node *mover)
{
    int price;
    int rr;
    int rrr;
    int ra_rrb;
    int rb_rra;

    rr = major(mover -> rot, mover -> target_rot);
    rrr = major(mover -> rev, mover -> target_rev);
    ra_rrb = mover -> rot + mover -> target_rev;
    rb_rra = mover -> rev + mover -> target_rot;
    price = minor(minor(rr, rrr), minor(ra_rrb, rb_rra));
    return (price);
}

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
  // printf("targeting %li\n", mover -> value);
    while (mover)
    {
        if (closestsmall(to, mover -> value) == mover -> value)
            t_value = getmax(to);
        else
            t_value = closestsmall(to, mover -> value);
//        printf("target of  %li  is %d\n", mover -> value, t_value);
        mover -> target = t_value;
        target = getnode(to, t_value);
        mover -> target_rot = target -> rot;
        mover -> target_rev = target -> rev;
        mover -> price = pricing(mover);
 //       printStack(*from, 'f');
        //mover -> price = minor((minor(major(mover -> rot, mover -> target_rot), major(mover -> rot, mover -> target_rot)), minor(mover -> rot + mover -> target_rev, mover -> rev + mover -> target_rot));
        mover = mover -> next;
    }
}

/*static void analyze_stack(t_node **from, t_node **to)
{
    //(void)to;
    t_node *mover;
    t_node *target;

    mover = *from;
    target = *to;
    refresh_indexes(from);
  //  printStack(*from, 'a');
    refresh_indexes(to);
 //   printStack(*to, 'b');

   //targeting(from, to);
   // printStack(*from, 'a');
}    */

static t_node *find_cheaper(t_node **a)
{
    t_node  *finder;
    t_node  *cheaper;
    int     best_price;

    cheaper = *a;
    finder = *a;
    best_price = cheaper -> price;
    while (finder)
    {
        if (finder -> price < best_price)
        {
            best_price = finder -> price;
            cheaper = finder;
        }
        finder = finder -> next;
    }
    return (cheaper);
}

static void migrate_b(t_node **a, t_node **b)
{
    t_node  *cheaper;

    cheaper = find_cheaper(a);
    printf("CHEAPER is %li moving upon %d at %d price\n", cheaper -> value, cheaper -> target, cheaper -> price);
    if (cheaper -> price == cheaper -> rot + cheaper -> target_rev)
    {
        printf("1]  %dra + %drrb\n", cheaper -> rot, cheaper -> target_rev);
        ra(a, cheaper -> rot);
        rrb(b, cheaper -> target_rev);
    }
    else if (cheaper -> price == cheaper -> rev + cheaper -> target_rot)
    {
        printf("2]  %drra + %drb\n", cheaper -> rev, cheaper -> target_rot);
        rra(a, cheaper -> rev);
        rb(b, cheaper -> target_rot);
    }
    else if (cheaper -> price == major(cheaper -> rot, cheaper -> target_rot))
    {
        printf("3]  %drr + %dra + %drb\n", minor(cheaper -> rot, cheaper -> target_rot), cheaper -> rot - cheaper -> target_rot, cheaper -> target_rot - cheaper -> rot);
        rr(a, b, minor(cheaper -> rot, cheaper -> target_rot));
        ra(a, cheaper -> rot - cheaper -> target_rot);
        rb(a, cheaper -> target_rot - cheaper -> rot);
    }
    else if (cheaper -> price == major(cheaper -> rev, cheaper -> rev))
    {   printf("4]  %drrr + %drra + %drrb\n", minor(cheaper -> rev, cheaper -> rev), cheaper -> rev - cheaper -> rev, cheaper -> target_rev - cheaper -> rev);
        rrr(a, b, minor(cheaper -> rev, cheaper -> rev));
        rra(a, cheaper -> rev - cheaper -> rev);
        rrb(a, cheaper -> target_rev - cheaper -> rev);
    }
    /*else if (cheaper -> price == major(cheaper -> rot, cheaper -> target_rot))
    {
        rr(a, b, cheaper -> price - minor(cheaper -> rot, cheaper -> target_rot));
        ra(a, cheaper -> rot - cheaper -> target_rot);
        rb(a, cheaper -> target_rot - cheaper -> rot);
    }
    else if (cheaper -> price == major(cheaper -> rev, cheaper -> rev))
    {
        rr(a, b, cheaper -> price - minor(cheaper -> rev, cheaper -> rev));
        ra(a, cheaper -> rev - cheaper -> rev);
        rb(a, cheaper -> target_rev - cheaper -> rev);
    }*/
    pb(a, b, 1);
//    printStack(*a, 'a');
//    printStack(*b, 'b');
}

/*static void populate_b(t_node **a, t_node **b)
{
    pb(a, b, 2);
    
    while (*a)
    {
        analyze_stack(a, b);
        targeting(a, b);
        migrate_b(a, b); 
    }
}*/

/*static void rev_sort(t_node **b)
{
    int pos;
    int len;

    len = stacklen(b);
    pos = getpos(b, getmax(b));
 //   printf("max value of b is in pos %d of %d elements", pos, len);
    if (pos < (len / 2))
        rb(b, pos);
    else
        rrb(b, (len - pos));
//    printStack(*b, '!');
}*/

void back2a(t_node **a, t_node **b)
{
    int len;
    
    len = stacklen(b);
    pa(a, b, len);
}

void    turk_sort(t_node** a, t_node **b)
{
    //                                      populate_b(a, b);
    pb(a, b, 2);
    while (*a)
    {
        //                                  analyze_stack(a, b);
        refresh_indexes(a);
        refresh_indexes(b);
        targeting(a, b);
        printStack(*a, 'a');
        printStack(*b, 'b');
        migrate_b(a, b); 
    }
    printf("stack b after migration\n");
    printStack(*b, 'b');
    //                                      rev_sort(b);
    int pos;
    int len;

    len = stacklen(b);
    pos = getpos(b, getmax(b));
 //   printf("max value of b is in pos %d of %d elements", pos, len);
    if (pos < (len / 2))
        rb(b, pos);
    else
        rrb(b, (len - pos));

    back2a(a, b);
}
