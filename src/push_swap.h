/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:01:47 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/11 20:09:33 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../inc/lib_ft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
//# include "../inc/ft_printf/ft_printf.h"

# define HASH_SIZE 1000

# define SMALL_SIZE_THRESHOLD 100
# define MEDIUM_SIZE_THRESHOLD 500
# define LARGE_SIZE_THRESHOLD 1000

# define MAX_BLOCK_SIZE 50
# define MIN_BLOCK_SIZE 3

// node to store integers in linked list
typedef struct s_node
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_med;
	bool			cheapest;

	struct s_node	*target;
	struct s_node	*next;
}					t_node;

// stack for sorting
typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				*array;
	int				size;
	int				min;
	int				max;
}					t_stack;

// node to store strings in linked list for hashset
typedef struct n_node
{
	char			*key;
	struct n_node	*next;
}					t_hashnode;

// hashset will have an array of these nodes
typedef struct s_hashset
{
	t_hashnode **array; // array of linked lists
}					t_hashset;

// math functions
double				ft_sqrt(double x);
double				ft_mean(int *array, int size);
double				ft_pow(double x, double y);
double				ft_std_dev(int *array, int size);
int					ft_abs(int x);
int					ft_max(int a, int b);

// movement functions
void				swap(t_stack **stack);
void				push(t_stack **stack1, t_stack **stack2);
void				rotate(t_stack **stack);
void				reverse_rotate(t_stack **stack);

// stack movement functions
void				push_a(t_stack **a, t_stack **b);
void				push_b(t_stack **a, t_stack **b);
void				rotate_a(t_stack **a);
void				rotate_b(t_stack **b);
void				rotate_ab(t_stack **a, t_stack **b);
void				swap_a(t_stack **a);
void				swap_b(t_stack **b);
void				swap_s(t_stack **a, t_stack **b);
void				reverse_rotate_a(t_stack **a);
void				reverse_rotate_b(t_stack **b);
void				reverse_ro_ab(t_stack **a, t_stack **b);

// stack creation functions
t_node				*new_node(int value);
t_stack				*new_stack(void);
void				node_to_stack(t_stack *stack, int value);
void				*set_array(t_stack **stack);

// stack free functions
void				free_stack(t_stack **stack);

// check functions
int					is_number(char *str);
int					is_integer(char *str);
int					is_duplicate(t_stack *stack, int value);
int					check_values(char **values);
int					is_sorted(t_stack *stack);
int					is_reverse_sorted(t_stack *stack);

// hash functions
unsigned int		ft_hash(char *str);
t_hashset			*ft_create_hash(void);
int					ft_insert_hash(t_hashset *hashset, char *key);
void				ft_free_hash(t_hashset *hashset);
int					ft_duplicate(t_hashset *hashset, char *key);

// find functions
int					find_min(t_stack *stack);
int					find_max(t_stack *stack);
int					find_second_min(t_stack *stack);
int					find_second_max(t_stack *stack);
int					find_nth_smallest(t_stack *stack);
int					find_position(t_stack *stack, t_node *node);
t_node				*find_max_node(t_stack *stack);
t_node				*find_min_node(t_stack *stack);

t_node				*find_cheapest(t_stack *stack);

// sort specific functions for 2 - 7 elements
void				sort_2(t_stack **a);
void				sort_3(t_stack **a);
void				sort_4(t_stack **a, t_stack **b);
void				sort_5(t_stack **a, t_stack **b);
void				ft_small_sort(t_stack **a, t_stack **b);

// parsing functions
int					ft_parser(t_stack *stack_a, int argc, char **argv);
int					parse_string(t_stack *stack, char *str);
int					parse_args(t_stack *stack, int argc, char **argv);
int					arg_checker(int argc, char **argv);
int					dup_checker(int argc, char **argv);
int					parser_checker(int argc, char **argv);
void				free_split(char **values);

// index functions
void				assign_index(t_stack **stack);

// sort B functions
void				ft_turk(t_stack **a, t_stack **b);
void				locking_targets(t_stack **a, t_stack **b);
void				set_cheapest(t_stack **a);
void				process_nodes_a(t_stack **a, t_stack **b);
void				process_nodes_b(t_stack **a, t_stack **b);
void				locking_targets_a(t_stack **a, t_stack **b);
void				locking_targets_b(t_stack **a, t_stack **b);

// optimizer functions
void				rotate_to_top(t_stack **a, t_node *optimal_node);
void				prepare_b(t_stack **b, t_node *node);

// cost functions
int					calculate_push_cost(t_stack **a, t_node *node);
void				calculate_cost_a(t_stack **a, t_stack **b);
void				calculate_cost_b(t_stack **a, t_stack **b);
t_node				*find_optimal_node(t_stack **a, t_stack **b);

// send functions
void				send_to_b(t_stack **a, t_stack **b);
void				send_to_a(t_stack **a, t_stack **b);
void				double_rotate_top(t_stack **a, t_stack **b,
						t_node *cheapest);
void				double_rev_rotate_top(t_stack **a, t_stack **b,
						t_node *cheapest);

void				get_a_ready(t_stack **a, t_node *top);
void				get_b_ready(t_stack **b, t_node *top);
void				move_min_to_top(t_stack **a);

// debug functions
void				print_stack(t_stack *stack, char stack_name);
void				print_array(int *array, int size, char *message);
void				print_partition(t_stack *stack);
void				print_index(t_stack *stack);
void				print_stack_values(t_stack *stack);

#endif
