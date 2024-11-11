/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:06:38 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/11 19:14:45 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_to_b(t_stack **a, t_stack **b)
{
	t_node	*cheapest;

	cheapest = find_cheapest(*a);
	if (cheapest == NULL || cheapest->target == NULL)
		return ;
	if (cheapest->above_med && cheapest->target->above_med)
		double_rotate_top(a, b, cheapest);
	else if ((!cheapest->above_med) && (!cheapest->target->above_med))
		double_rev_rotate_top(a, b, cheapest);
	get_a_ready(a, cheapest);
	get_b_ready(b, cheapest->target);
	push_b(a, b);
}

void	send_to_a(t_stack **a, t_stack **b)
{
	get_a_ready(a, (*b)->head->target);
	push_a(a, b);
}

static void	final_rotation(t_stack **a, int rotations)
{
	int	i;
	int	size;

	size = (*a)->size;
	i = 0;
	if (rotations <= size / 2)
	{
		while (i < rotations)
		{
			rotate_a(a);
			i++;
		}
	}
	else
	{
		while (i < size - rotations)
		{
			reverse_rotate_a(a);
			i++;
		}
	}
}

void	move_min_to_top(t_stack **a)
{
	t_node	*min_node;
	t_node	*current;
	int		size;
	int		rotations;

	min_node = find_min_node(*a);
	rotations = 0;
	current = (*a)->head;
	while (current->value != min_node->value)
	{
		current = current->next;
		rotations++;
	}
	size = (*a)->size;
	if (rotations == 0)
		return ;
	final_rotation(a, rotations);
}
