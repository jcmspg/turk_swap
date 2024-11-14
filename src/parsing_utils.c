/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:25:36 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/14 18:49:05 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function to parse the arguments and store them in the stack
int	arg_checker(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	if (!check_values(argv + 1))
		return (1);
	return (0);
}

int	dup_checker(int argc, char **argv)
{
	int			i;
	t_hashset	*hashset;

	i = 1;
	hashset = ft_create_hash();
	if (!hashset)
		return (1);
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-0") == 0)
			argv[i] = "0";
		if (!ft_insert_hash(hashset, argv[i]))
		{
			ft_free_hash(hashset);
			return (1);
		}
		i++;
	}
	ft_free_hash(hashset);
	return (0);
}

int	parser_checker(int argc, char **argv)
{
	if (arg_checker(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (dup_checker(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

void	free_split(char **values)
{
	int	i;

	i = 0;
	if (!values)
		return ;
	while (values[i])
	{
		free(values[i]);
		i++;
	}
	free(values);
}
