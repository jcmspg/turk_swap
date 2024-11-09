/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:12:54 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/09 00:40:18 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void double_rotate_top(t_stack **a, t_stack **b, t_node *cheapest)
{
    while ((*a)->head != cheapest && (*b)->head != cheapest->target)
        rotate_ab(a, b);
//    assign_index(*a);
//    assign_index(*b);
}

void double_rev_rotate_top(t_stack **a, t_stack **b, t_node *cheapest)
{
    while ((*a)->head != cheapest && (*b)->head != cheapest->target)
        reverse_ro_ab(a, b);
//    assign_index(*a);
//    assign_index(*b);
}

void get_a_ready(t_stack **a, t_node *top)
{
    while ((*a)->head != top)
    {
        if (top->above_med)
            rotate_a(a);
        else
            reverse_rotate_a(a);
    }
}

void get_b_ready(t_stack **b, t_node *top)
{
    while ((*b)->head != top)
    {
        if (top->above_med)
            rotate_b(b);
        else
            reverse_rotate_b(b);
    }
}
