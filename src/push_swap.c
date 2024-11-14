/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:01:00 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/14 18:31:26 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = new_stack();
	stack_b = new_stack();
	if (ft_parser(stack_a, argc, argv) || is_sorted(stack_a))
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (1);
	}
	if (stack_a->size <= 5)
		ft_small_sort(&stack_a, &stack_b);
	else
		ft_turk(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
