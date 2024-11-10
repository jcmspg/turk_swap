/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:51:02 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/09 01:52:57 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static void	debug_stacks(t_stack *a, t_stack *b)
//{
//    print_stack(a, 'A');
//    print_stack(b, 'B');
//    printf("------\n");
//}





void	ft_turk(t_stack **a, t_stack **b)
{
    int size;

    size = (*a)->size;

    if (size-- > 3 && !is_sorted(*a))
        push_b(a, b);
    if (size-- > 3 && !is_sorted(*a))
        push_b(a, b);

    print_stack_values(*a);

    while ((*a)->size > 3 && !is_sorted(*a))
    {
        process_nodes_a(a, b);
        send_to_b(a, b);
    }

    print_stack_values(*a);

    sort_3(a);
   	
    while ((*b)->size > 0)
	{
		process_nodes_b(a, b);
		send_to_a(a, b);
	}
    
//    print_stack_values(*a);
//    print_stack_values(*b);
//
//    debug_stacks(*a, *b);
    assign_index(a);
	move_min_to_top(a);
//    debug_stacks(*a, *b);
}
