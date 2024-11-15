/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:19:47 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/15 16:55:25 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"
#include "push_swap_bonus.h"

static void	free_stacks(t_stack **a, t_stack **b)
{
	free(*a);
	free(*b);
}

void	show_error(t_stack **a, t_stack **b)
{
	free_stacks(a, b);
	ft_putstr_fd("Error\n", 2);
}

int	parse_command(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b);
	else
    {
		show_error(a, b);
        return (0);
    }
    return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = new_stack();
	b = new_stack();
	if (ft_parser(a, argc, argv))
		return (1);
	line = get_next_line(0);
	while (line && *line != 4)
	{
		if (!parse_command(line, &a, &b))
        {
            free(line);
            return (1);
        }
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (is_sorted(a) && !b->size)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stacks(&a, &b);
	return (0);
}
