/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:49:58 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/09 02:09:36 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    calculate_cost_a(t_stack **a, t_stack **b)
{
    t_node *current_a;
    int size_a;
    int size_b;

    size_a = (*a)->size;
    size_b = (*b)->size;
    current_a = (*a)->head;
    while (current_a)
    {
        current_a->push_cost = (current_a->index);
        if (current_a->target)
        {
            if (!current_a->above_med)
                current_a->push_cost = size_a - (current_a->index);
            if (current_a->target->above_med)
                current_a->push_cost += (current_a->target->index);
            else
                current_a->push_cost += size_b - (current_a->target->index);}
        current_a = current_a->next;
    }
}
