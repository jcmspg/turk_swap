/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:15:07 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/11 18:15:15 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max_node(t_stack *stack)
{
	t_node	*current;
	t_node	*max_node;

	if (!stack || !stack->head)
		return (NULL);
	current = stack->head;
	max_node = stack->head;
	while (current != NULL)
	{
		if (current->value > max_node->value)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

t_node	*find_min_node(t_stack *stack)
{
	t_node	*current;
	t_node	*min_node;

	if (!stack || !stack->head)
		return (NULL);
	current = stack->head;
	min_node = stack->head;
	while (current != NULL)
	{
		if (current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

t_node	*find_cheapest(t_stack *stack)
{
	t_node	*current;
	t_node	*cheapest;
	int		min_cost;

	if (!stack || !stack->head)
		return (NULL);
	current = stack->head;
	cheapest = NULL;
	min_cost = INT_MAX;
	while (current != NULL)
	{
		if (current->push_cost < min_cost)
		{
			min_cost = current->push_cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}
