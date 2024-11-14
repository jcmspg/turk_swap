/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:16:07 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/14 20:11:16 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_integer(char *str)
{
	long	nbr;
	int		i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	if (str[i] == '\0')
		return (1);
	if (ft_strlen(str + i) > 10)
		return (0);
	nbr = ft_atol(str);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	return (1);
}

int	check_values(char **values)
{
	int	i;

	i = 0;
	while (values[i])
	{
		if (!is_number(values[i]) || !is_integer(values[i]) || !values[i][0])
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_reverse_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current->next)
	{
		if (current->value < current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
