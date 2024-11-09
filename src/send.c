/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:06:38 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/09 02:00:11 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_to_b(t_stack **a, t_stack **b)
{
    t_node  *cheapest;

    cheapest = find_cheapest(*a);

    if (cheapest == NULL || cheapest->target == NULL)
    {
        printf("Cheapest is NULL\n");
        return ;
    }

    printf("Cheapest: %d\n", cheapest->value);
    printf("Target: %d\n", cheapest->target->value);

    if (cheapest->above_med && cheapest->target->above_med)
        double_rotate_top(a, b, cheapest);
    else if (!cheapest->above_med && !cheapest->target->above_med)
        double_rev_rotate_top(a, b, cheapest); 
   get_a_ready(a, cheapest); 
   get_b_ready(b, cheapest->target);
   push_b(a, b);
}

void    send_to_a(t_stack **a, t_stack **b)
{
    t_node  *cheapest;

    cheapest = find_cheapest(*b);

    if (cheapest == NULL || cheapest->target == NULL)
    {
        printf("Cheapest is NULL\n");
        return ;
    }
    
    printf("Cheapest: %d\n", cheapest->value);
    printf("Target: %d\n", cheapest->target->value);

    if (cheapest->above_med && cheapest->target->above_med)
        double_rotate_top(b, a, cheapest);
    else if (!cheapest->above_med && !cheapest->target->above_med)
        double_rev_rotate_top(b, a, cheapest); 
   get_b_ready(b, cheapest); 
   get_a_ready(a, cheapest->target);
   push_a(b, a);
}

void move_min_to_top(t_stack **a)
{
    t_node *min;
    t_node *current;

    min = find_min_node(*a);
    current = (*a)->head;
    while (current != min)
    {
        if (min->above_med)
            rotate_a(a);
        else
            reverse_rotate_a(a);
        current = (*a)->head;
    }
}

