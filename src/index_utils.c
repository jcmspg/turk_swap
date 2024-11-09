/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:52:01 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/09 01:17:34 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to assign index to each node in the stack
void	assign_index(t_stack *stack)
{
	t_node	*current;
	int		index;
	int		median;
    
    current = stack->head;
    index = 0;
    
    if (!stack || !stack->head)
    {
        printf("Error\n");
        printf("Stack is NULL\n");
        return ;
    }

    median = stack->size / 2;
    while (current)
    {
        current->index = index;
        current->above_med = index >= median;
        printf("Value: %d, Index: %d, Above Median: %d\n", current->value, current->index, current->above_med);
        index++;
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
