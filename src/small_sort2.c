/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:17:07 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/11 19:29:52 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a)
{
	t_node	*biggest;

	if (is_sorted(*a))
		return ;
	biggest = find_max_node(*a);
	if ((*a)->head == biggest)
		rotate_a(a);
	else if ((*a)->head->next == biggest)
		reverse_rotate_a(a);
	if ((*a)->head->value > (*a)->head->next->value)
		swap_a(a);
}
