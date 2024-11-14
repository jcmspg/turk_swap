/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:03:34 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/14 17:54:16 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// hash function
unsigned int	ft_hash(char *str)
{
	unsigned long	hash;
	int				c;

	hash = 5381;
	if (ft_strcmp(str, "-0") == 0)
		str = "0";
	c = *str;
	while (c)
	{
		hash = ((hash << 5) + hash) + c;
		str++;
		c = *str;
	}
	return (hash % HASH_SIZE);
}

// create the hashset
t_hashset	*ft_create_hash(void)
{
	t_hashset	*hashset;
	int			i;

	hashset = (t_hashset *)malloc(sizeof(t_hashset));
	if (!hashset)
		return (NULL);
	hashset->array = (t_hashnode **)malloc(HASH_SIZE * sizeof(t_hashnode *));
	i = 0;
	while (i < HASH_SIZE)
	{
		hashset->array[i] = NULL;
		i++;
	}
	return (hashset);
}

int	ft_insert_hash(t_hashset *hashset, char *key)
{
	unsigned int	index;
	t_hashnode		*new_node;
	t_hashnode		*tmp;

	index = ft_hash(key);
	tmp = hashset->array[index];
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
			return (0);
		tmp = tmp->next;
	}
	new_node = (t_hashnode *)malloc(sizeof(t_hashnode));
	if (!new_node)
		return (0);
	new_node->key = ft_strdup(key);
	new_node->next = hashset->array[index];
	hashset->array[index] = new_node;
	return (1);
}

// check if string exists in the hashset
int	ft_duplicate(t_hashset *hashset, char *key)
{
	unsigned int	index;
	t_hashnode		*tmp;

	if (ft_strcmp(key, "-0") == 0)
		key = "0";
	index = ft_hash(key);
	tmp = hashset->array[index];
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_free_hash(t_hashset *hashset)
{
	t_hashnode	*tmp;
	t_hashnode	*next;
	int			i;

	i = 0;
	while (i < HASH_SIZE)
	{
		tmp = hashset->array[i];
		while (tmp)
		{
			next = tmp;
			tmp = tmp->next;
			free(next->key);
			free(next);
		}
		hashset->array[i] = NULL;
		i++;
	}
	free(hashset->array);
	free(hashset);
}
