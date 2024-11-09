/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:16:58 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/09 01:58:35 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

// find the minimum value in the stack
int find_min(t_stack *stack)
{
    t_node *temp;
    int min;

    temp = stack->head;
    min = INT_MAX;
    while (temp)
    {
        if (temp->value < min)
            min = temp->value;
        temp = temp->next;
    }
    return (min);
}

// find the maximum value in the stack
int find_max(t_stack *stack)
{
    t_node *temp;
    int max;

    temp = stack->head;
    max = INT_MIN;
    while (temp)
    {
        if (temp->value > max)
            max = temp->value;
        temp = temp->next;
    }
    return (max);
}

// find the second minimum value in the stack
int find_second_min(t_stack *stack)
{
    t_node *temp;
    int min;
    int second_min;

    temp = stack->head;
    min = INT_MAX;
    second_min = INT_MAX;
    while (temp)
    {
        if (temp->value < min)
        {
            second_min = min;
            min = temp->value;
        }
        else if (temp->value < second_min && temp->value != min)
            second_min = temp->value;
        temp = temp->next;
    }
    return (second_min);
}

t_node *find_max_node(t_stack *stack)
{
    if (!stack || !stack->head)
        return (NULL);

    t_node *current;
    t_node *max_node;

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

t_node *find_min_node(t_stack *stack)
{
    if (!stack || !stack->head)
        return (NULL);

    t_node *current;
    t_node *min_node;

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

t_node *find_cheapest(t_stack *stack)
{
    if (!stack || !stack->head)
        return (NULL);

    t_node *current;
    t_node *cheapest;
    int min_cost;

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
    if (cheapest == NULL)
        return (NULL);

    if (cheapest->target == NULL)
        return (NULL);

    if (cheapest)
        cheapest->cheapest = true;

    return (cheapest);
}

