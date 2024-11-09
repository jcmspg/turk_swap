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
        return ;

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
    get_a_ready(a, (*b)->head->target);
    push_a(a, b);
}

//void move_min_to_top(t_stack **a)
//{
//    t_node *current;
//    t_node *min;
//
//    current = (*a)->head;
//    min = find_min_node(*a);
//
//    while (current->value != min->value)
//    {
//        if (min->above_med)
//            rotate_a(a);
//        else
//            reverse_rotate_a(a);
//        current = (*a)->head;
//    }
//}

void move_min_to_top(t_stack **a)
{
    t_node *min_node = find_min_node(*a);
  //  printf("Min node value: %d\n", min_node->value);

    int rotations = 0;
    t_node *current = (*a)->head;
    while (current->value != min_node->value)
    {
        current = current->next;
        rotations++;
    }

    int size = (*a)->size;
    if (rotations == 0)  // Already at the top, no need to rotate
        return;

    if (rotations <= size / 2)
    {
        for (int i = 0; i < rotations; i++)
            rotate_a(a);
    }
    else
    {
        for (int i = 0; i < size - rotations; i++)
            reverse_rotate_a(a);
    }
}

