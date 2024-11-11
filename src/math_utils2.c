/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:21:46 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/11 18:46:58 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function to calculate the standard deviation of a set of numbers
double	ft_std_dev(int *array, int size)
{
	double	mean;
	double	std_dev;
	double	sum;
	int		i;

	mean = ft_mean(array, size);
	sum = 0;
	i = 0;
	while (i < size)
	{
		sum += ft_pow(array[i] - mean, 2);
		i++;
	}
	std_dev = ft_sqrt(sum / size);
	return (std_dev);
}

// function to calculate the median of a set of numbers
double	ft_median(int *array, int size)
{
	double	median;
	int		i;

	median = 0;
	i = 0;
	while (i < size)
	{
		median += array[i];
		i++;
	}
	median /= size;
	return (median);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
