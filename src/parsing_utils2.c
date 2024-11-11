/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:35:03 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/11 18:39:38 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_string(t_stack *stack_a, char *str)
{
	char	**values;
	int		i;
	int		argc;

	values = ft_split(str, ' ');
	if (!values)
		return (1);
	i = 0;
	argc = 0;
	while (values[argc])
		argc++;
	if (parser_checker(argc, values))
	{
		free_split(values);
		return (1);
	}
	while (i < argc)
	{
		node_to_stack(stack_a, ft_atoi(values[i]));
		i++;
	}
	return (0);
}

int	parse_args(t_stack *stack_a, int argc, char **argv)
{
	int	i;

	i = 1;
	if (parser_checker(argc, argv))
		return (1);
	while (i < argc)
	{
		if (!is_number(argv[i]) || !is_integer(argv[i]))
		{
			ft_putstr_fd("Error.\n", 2);
			return (1);
		}
		node_to_stack(stack_a, ft_atoi(argv[i]));
		i++;
	}
	return (0);
}

int	ft_parser(t_stack *stack_a, int argc, char **argv)
{
	if (argc < 2)
		return (1);
	if (argc == 2)
		return (parse_string(stack_a, argv[1]));
	else
		return (parse_args(stack_a, argc, argv));
}
