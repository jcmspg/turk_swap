/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:52:01 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/11 18:26:31 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack **stack)
{
	int		i;
	int		median;
	t_node	*current;

	if (!*stack)
		return ;
	i = 0;
	median = (*stack)->size / 2;
	current = (*stack)->head;
	while (current != NULL)
	{
		current->index = i;
		if (i <= median)
			current->above_med = true;
		else
			current->above_med = false;
		++i;
		current = current->next;
	}
}

// function to print all the nodes and their indexes
void	print_index(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp)
	{
		printf("Value: %d, Index: %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
}
