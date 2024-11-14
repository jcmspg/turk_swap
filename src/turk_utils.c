/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:31:04 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/14 18:49:56 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cheapest(t_stack **a)
{
	t_node	*cheapest;
	t_node	*current_a;
	int		lowest_cost;

	if (a == NULL || (*a)->head == NULL)
		return ;
	if (!(*a)->head)
		return ;
	current_a = (*a)->head;
	lowest_cost = INT_MAX;
	cheapest = NULL;
	while (current_a)
	{
		if (current_a->push_cost < lowest_cost)
		{
			lowest_cost = current_a->push_cost;
			cheapest = current_a;
		}
		current_a = current_a->next;
	}
	if (cheapest != NULL)
		cheapest->cheapest = true;
}

void	process_nodes_a(t_stack **a, t_stack **b)
{
	assign_index(a);
	assign_index(b);
	locking_targets_a(a, b);
	calculate_cost_a(a, b);
	set_cheapest(a);
}

void	process_nodes_b(t_stack **a, t_stack **b)
{
	assign_index(a);
	assign_index(b);
	locking_targets_b(a, b);
}
/*
void	print_stack(t_stack *stack, char stack_name)
{
	t_node	*current;

	current = stack->head;
	printf("Stack %c: ", stack_name);
	while (current != NULL)
	{
		printf("[%d] -> ", current->value);
		current = current->next;
	}
	printf("NULL\n");
}
*/
