/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:26:08 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/11 18:34:10 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
