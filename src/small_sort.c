/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:48:41 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/11 19:29:54 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sort 2 numbers
void	sort_2(t_stack **a)
{
	if ((*a)->head->value > (*a)->head->next->value)
		swap_a(a);
}

// sort 4 numbers
void	sort_4(t_stack **a, t_stack **b)
{
	int	min;

	min = find_min(*a);
	while ((*a)->head->value != min)
		rotate_a(a);
	push_b(a, b);
	sort_3(a);
	push_a(a, b);
}

// sort 5 numbers
void	sort_5(t_stack **a, t_stack **b)
{
	int	min;
	int	second_min;

	min = find_min(*a);
	second_min = find_second_min(*a);
	while ((*a)->size > 3)
	{
		if ((*a)->head->value == min || (*a)->head->value == second_min)
			push_b(a, b);
		else
			rotate_a(a);
	}
	sort_3(a);
	if ((*b)->head->value > (*b)->head->next->value)
	{
		push_a(a, b);
		push_a(a, b);
	}
	else
	{
		rotate_b(b);
		push_a(a, b);
		push_a(a, b);
	}
}

// if args are 2, 3, 4 or 5, sort them
void	ft_small_sort(t_stack **a, t_stack **b)
{
	if ((*a)->size == 2)
		sort_2(a);
	else if ((*a)->size == 3)
		sort_3(a);
	else if ((*a)->size == 4)
		sort_4(a, b);
	else if ((*a)->size == 5)
		sort_5(a, b);
}
