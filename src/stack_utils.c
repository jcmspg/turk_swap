/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:40:59 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/09 02:10:58 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// stack functions

// array to store the stack values
void *set_array(t_stack **stack)
{
    t_node	*tmp;
    int		i;

    i = 0;
    tmp = (*stack)->head;
    (*stack)->array = (int *)malloc(sizeof(int) * (*stack)->size);
    if (!(*stack)->array)
        return (NULL);
    while (tmp)
    {
        (*stack)->array[i] = tmp->value;
        i++;
        tmp = tmp->next;
    }
    return (0);
}

// create a new node
t_node	*new_node(int value)
{
    t_node	*node;

    node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->value = value;
    node->index = -1;
    node->next = NULL;
    node->push_cost = 0;
    node->above_med = false;
    node->cheapest = false;
    node->target = NULL;
    return (node);
}

// create a new stack
t_stack	*new_stack()
{
    t_stack	*stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;
    stack->min = INT_MAX;
    stack->max = INT_MIN;
    stack->array = NULL;
    return (stack);
}

// push a new node into the stack
void    node_to_stack(t_stack *stack, int value)
{
    t_node	*node;

    node = new_node(value);
    if (!node)
        return ;
    if (!stack->head)
    {
        stack->head = node;
        stack->tail = node;
    }
    else
    {
        stack->tail->next = node;
        stack->tail = node;
    }
    stack->size++;
}

// free the nodes and the stack
void	free_stack(t_stack **stack)
{
    t_node	*tmp;
    t_node	*next;

    tmp = (*stack)->head;
    while (tmp)
    {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    
    if ((*stack)->array != NULL)
        free((*stack)->array);

    free(*stack);
    *stack = NULL;
}

void print_stack(t_stack *stack, char stack_name)
{
    t_node *current = stack->head;
    printf("Stack %c: ", stack_name);
    while (current != NULL)
    {
        printf("[%d] -> ", current->index);
        current = current->next;
    }
    printf("NULL\n");
}

