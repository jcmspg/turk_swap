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

static int	calculate_push_cost_a(t_stack **a, t_node *node)
{
	int		cost;
	t_node	*current;

	if (!a || !(*a) || !(*a)->head || !node)
		return (INT_MAX);
	cost = 0;
	current = (*a)->head;
	while (current)
	{
		if (current->index == node->index)
			break ;
		current = current->next;
		cost++;
	}
	if (current == NULL)
		return (INT_MAX);
	return (cost);
}

static int calculate_push_cost_b(t_stack **b, t_node *node)
{
    int		cost;
    t_node	*current;

    if (!b || !(*b) || !(*b)->head || !node)
        return (INT_MAX);
    cost = 0;
    current = (*b)->head;
    while (current)
    {
        if (current->index == node->index)
            break ;
        current = current->next;
        cost++;
    }
    if (current == NULL)
        return (INT_MAX);
    return (cost);
}



// ammount of operations to push node to top of a and its target to top of b
void	calculate_total_cost_a(t_stack **a, t_stack **b)
{
	t_node	*current_a;


	if (!a || !(*a) || !(*a)->head || !b || !(*b) || !(*b)->head)
		return ;
	current_a = (*a)->head;

	while (current_a)
	{
		current_a->push_cost = calculate_push_cost_a(a, current_a);
		if (current_a->target)
			current_a->push_cost += calculate_push_cost_b(b, current_a->target);
		else
			current_a->push_cost = INT_MAX;
		current_a = current_a->next;
	}
}

void calculate_total_cost_b(t_stack **a, t_stack **b)
{
    t_node	*current_b;

    if (!a || !(*a) || !(*a)->head || !b || !(*b) || !(*b)->head)
        return ;
    current_b = (*b)->head;

    while (current_b)
    {
        current_b->push_cost = calculate_push_cost_b(b, current_b);
        if (current_b->target)
            current_b->push_cost += calculate_push_cost_a(a, current_b->target);
        else
            current_b->push_cost = INT_MAX;
        current_b = current_b->next;
    }
}
