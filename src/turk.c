/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:51:02 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/14 18:30:17 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	debug_stacks(t_stack *a, t_stack *b)
//{
//    print_stack(a, 'A');
//    print_stack(b, 'B');
//    printf("------\n");
//}

void	ft_turk(t_stack **a, t_stack **b)
{
	int	size;

	size = (*a)->size;
	if (size-- > 3 && !is_sorted(*a))
		push_b(a, b);
	if (size-- > 3 && !is_sorted(*a))
		push_b(a, b);
	while ((*a)->size > 3 && !is_sorted(*a))
	{
		process_nodes_a(a, b);
		send_to_b(a, b);
	}
	sort_3(a);
	while ((*b)->size > 0)
	{
		process_nodes_b(a, b);
		send_to_a(a, b);
	}
	assign_index(a);
	move_min_to_top(a);
}
