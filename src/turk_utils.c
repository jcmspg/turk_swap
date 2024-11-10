/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:31:04 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/10 19:01:14 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void locking_targets_a(t_stack **a, t_stack **b)
{
    t_node *current_a;
    t_node *current_b;
    t_node *target;
    t_node *max;
    int best_match;
    
    current_a = (*a)->head;
    max = NULL;
    while (current_a)
    {
        best_match = INT_MIN;
        current_b = (*b)->head;
        target = NULL;

        while (current_b)
        {
            if (current_b->value < current_a->value && current_b->value > best_match)
            {
                best_match = current_b->value;
                target = current_b;
            }
            current_b = current_b->next;
        }
        if (best_match == INT_MIN)
        {
            max = find_max_node(*b);
            current_a->target = max;
        }
        else
            current_a->target = target;
        current_a = current_a->next;
    }
}

void locking_targets_b(t_stack **a, t_stack **b)
{
    t_node *current_a;
    t_node *current_b;
    t_node *target;
    t_node *min;
    int best_match;

    current_b = (*b)->head;
    min = NULL;
    while(current_b)
    {
        best_match = INT_MAX;
        current_a = (*a)->head;
        target = NULL;
        while (current_a)
        {
            if (current_a->value > current_b->value && current_a->value < best_match)
            {
                best_match = current_a->value;
                target = current_a;
            }
            current_a = current_a->next;
        }
        if (best_match == INT_MAX)
        {
            min = find_min_node(*a);
            current_b->target = min;
        }
        else
            current_b->target = target;
        current_b = current_b->next;
    }
}


void set_cheapest(t_stack **a)
{
    if (a == NULL || (*a)->head == NULL)
        return ;

    t_node *cheapest;
    t_node *current_a;
    int lowest_cost;
    
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

void process_nodes_a(t_stack **a, t_stack **b)
{
    assign_index(a);
    assign_index(b);
    locking_targets_a(a, b);
    calculate_cost_a(a, b);
    set_cheapest(a);
}

void process_nodes_b(t_stack **a, t_stack **b)
{
    assign_index(a);
    assign_index(b);
    locking_targets_b(a, b);
}
