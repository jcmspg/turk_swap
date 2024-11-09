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

static void	debug_stacks(t_stack *a, t_stack *b)
{
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("------\n");
}





void	ft_turk(t_stack **a, t_stack **b)
{
	if ((*a)->size > 3)
	{
		push_b(a, b);
		push_b(a, b);
	}
	// repeat process until stack A is empty
	while ((*a)->size > 3)
	{
        printf("calling process_nodes_a\n");
		process_nodes_a(a, b);
		send_to_b(a, b);
	}

	sort_3(a);
   	
    while ((*b)->size > 0)
	{
        printf("calling process_nodes_b\n");
		process_nodes_b(a, b);
		send_to_a(a, b);
	}

	assign_index(*a);
	move_min_to_top(a);
    debug_stacks(*a, *b);
}
