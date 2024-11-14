/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:05:57 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/14 20:08:21 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_best_match_a(t_node *a, int b_value)
{
	t_node	*best_match;
	int		min_diff;

	best_match = NULL;
	min_diff = INT_MAX;
	while (a)
	{
		if (a->value > b_value && a->value < min_diff)
		{
			min_diff = a->value;
			best_match = a;
		}
		a = a->next;
	}
	return (best_match);
}

t_node	*find_best_match_b(t_node *b, int a_value)
{
	t_node	*best_match;
	int		max_diff;

	best_match = NULL;
	max_diff = INT_MIN;
	while (b)
	{
		if (b->value < a_value && b->value > max_diff)
		{
			max_diff = b->value;
			best_match = b;
		}
		b = b->next;
	}
	return (best_match);
}

void	locking_targets_a(t_stack **a, t_stack **b)
{
	t_node	*current_a;
	t_node	*best_match;

	current_a = (*a)->head;
	while (current_a)
	{
		best_match = find_best_match_b((*b)->head, current_a->value);
		if (best_match)
			current_a->target = best_match;
		else
			current_a->target = find_max_node(*b);
		current_a = current_a->next;
	}
}

void	locking_targets_b(t_stack **a, t_stack **b)
{
	t_node	*current_b;
	t_node	*best_match;

	current_b = (*b)->head;
	while (current_b)
	{
		best_match = find_best_match_a((*a)->head, current_b->value);
		if (best_match)
			current_b->target = best_match;
		else
			current_b->target = find_min_node(*a);
		current_b = current_b->next;
	}
}

/*
void	print_stack_values(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	printf("Stack values: ");
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}
*/
