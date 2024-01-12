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

static void targeting2b(t_node **from, t_node **to)
{
    t_node *mover;
    t_node *target;
    int     t_value;

    mover = *from;
    while (mover)
    {
        if (closestsmall(to, mover -> value) == mover -> value)
            t_value = getmax(to);
        else
            t_value = closestsmall(to, mover -> value);
        mover -> target = t_value;
        target = getnode(to, t_value);
        mover -> target_rot = target -> rot;
        mover -> target_rev = target -> rev;
        mover -> price = pricing(mover);
        mover = mover -> next;
    }
}

static void targeting2a(t_node **from, t_node **to)  //from b ->> to a
{
    t_node *mover;
    t_node *target;
    int     t_value;

    mover = *from;
    while (mover)
    {
        if (closestbig(to, mover -> value) == mover -> value)
            t_value = getmin(to);
        else
            t_value = closestbig(to, mover -> value);
        mover -> target = t_value;
        target = getnode(to, t_value);
        mover -> target_rot = target -> rot;
        mover -> target_rev = target -> rev;
        mover -> price = pricing(mover);
        mover = mover -> next;
    }
}

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

static void migrate2a(t_node **a, t_node **b)
{
    t_node  *cheaper;

    cheaper = find_cheaper(b);
 //   printf("CHEAPER is %li moving upon %d at %d price\n", cheaper -> value, cheaper -> target, cheaper -> price);
    if (cheaper -> price == cheaper -> rot + cheaper -> target_rev)
    {
 //       printf("1]  %drb + %drra\n", cheaper -> rot, cheaper -> target_rev);
        rb(b, cheaper -> rot);
        rra(a, cheaper -> target_rev);
    }
    else if (cheaper -> price == cheaper -> rev + cheaper -> target_rot)
    {
 //       printf("2]  %drrb + %dra\n", cheaper -> rev, cheaper -> target_rot);
        rrb(b, cheaper -> rev);
        ra(a, cheaper -> target_rot);
    }
    else if (cheaper -> price == major(cheaper -> rot, cheaper -> target_rot))
    {
 //       printf("3]  %drr + %dra + %drb\n", minor(cheaper -> rot, cheaper -> target_rot), cheaper -> rot - cheaper -> target_rot, cheaper -> target_rot - cheaper -> rot);
        rr(a, b, minor(cheaper -> rot, cheaper -> target_rot));
        rb(b, cheaper -> rot - cheaper -> target_rot);
        ra(a, cheaper -> target_rot - cheaper -> rot);
    }
    else if (cheaper -> price == major(cheaper -> rev, cheaper -> rev))
    {   
 //       printf("4]  %drrr + %drrb + %drra\n", minor(cheaper -> rev, cheaper -> rev), cheaper -> rev - cheaper -> rev, cheaper -> target_rev - cheaper -> rev);
        rrr(a, b, minor(cheaper -> rev, cheaper -> rev));
        rrb(b, cheaper -> rev - cheaper -> rev);
        rra(a, cheaper -> target_rev - cheaper -> rev);
    }
    pa(a, b, 1);
//    printStack(*a, 'a');
//    printStack(*b, 'b');
}

static void migrate2b(t_node **a, t_node **b)
{
    t_node  *cheaper;

    cheaper = find_cheaper(a);
    if (cheaper -> price == cheaper -> rot + cheaper -> target_rev)
    {
        ra(a, cheaper -> rot);
        rrb(b, cheaper -> target_rev);
    }
    else if (cheaper -> price == cheaper -> rev + cheaper -> target_rot)
    {
        rra(a, cheaper -> rev);
        rb(b, cheaper -> target_rot);
    }
    else if (cheaper -> price == major(cheaper -> rot, cheaper -> target_rot))
    {
        rr(a, b, minor(cheaper -> rot, cheaper -> target_rot));
        ra(a, cheaper -> rot - cheaper -> target_rot);
        rb(b, cheaper -> target_rot - cheaper -> rot);
    }
    else if (cheaper -> price == major(cheaper -> rev, cheaper -> rev))
    {   
        rrr(a, b, minor(cheaper -> rev, cheaper -> rev));
        rra(a, cheaper -> rev - cheaper -> rev);
        rrb(b, cheaper -> target_rev - cheaper -> rev);
    }
    pb(a, b, 1);
}
void back2a(t_node **a, t_node **b)
{
        refresh_indexes(a);
        refresh_indexes(b);
        targeting2a(b, a);
//        printf("****stacks after targeting2a\n");
 //       printStack(*a, 'a');
 //       printStack(*b, 'b');
        migrate2a(a, b);

        //pa(a, b, 1);
}

static void min2top(t_node **a)
{
    int pos;
    int len;

    len = stacklen(a);
    pos = getpos(a, getmin(a));
 //   printf("min value of a is in pos %d of %d elements", pos, len);
    if (pos < (len / 2))
        ra(a, pos);
    else
        rra(a, (len - pos));
//    printStack(*b, '!');
}

void    turk_sort(t_node** a, t_node **b)
{
    //                                      populate_b(a, b);
    pb(a, b, 2);
    while (stacklen(a) > 3)
    {
        refresh_indexes(a);
        refresh_indexes(b);
        targeting2b(a, b);
        migrate2b(a, b); 
    }
    sort3(a);
//    printf("****stacks after migration2b and sort3\n");
 //   printStack(*a, 'a');
//    printStack(*b, 'b');
    while (*b)
       back2a(a, b);
    min2top(a);
}
