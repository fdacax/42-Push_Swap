/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:12:37 by dmeirele          #+#    #+#             */
/*   Updated: 2024/05/21 14:27:56 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef enum operations
{
	SA,
	SB,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}			t_operation;

typedef struct s_stack
{
	int				data;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* ************************************************************************** */
/*                              stack_error                                   */
/* ************************************************************************** */

void	ft_print_error(void);
void	check_errors(int argc, char **argv, int *len);
int		check_numbers(char **input);
int		check_arg(char **str, int *len);
void	check_duplicate(int *nbr, int len);

/* ************************************************************************** */
/*                              stack_init                                    */
/* ************************************************************************** */

int		*add_numbers(char **str, int *nbr);
void	init_stack_a(t_stack **stack, int *data, int len);
long	ft_atol(const char *str);
void	add_node(t_stack **stack, int n);
t_stack	*find_last_node(t_stack *stack);

/* ************************************************************************** */
/*                              stack_init2                                   */
/* ************************************************************************** */

void	init_nodes_sa(t_stack *sa, t_stack *sb);
void	current_index(t_stack *stack);
void	set_target_to_sb(t_stack *sa, t_stack *sb);
void	set_cost(t_stack *sa, t_stack *sb);
void	set_cheapest(t_stack *stack);

/* ************************************************************************** */
/*                              stack_init3                                   */
/* ************************************************************************** */

void	init_nodes_sb(t_stack *sa, t_stack *sb);
void	set_target_to_sa(t_stack *sa, t_stack *sb);

/* ************************************************************************** */
/*                              stack_utils                                   */
/* ************************************************************************** */

void	shift_stack(t_stack *popped);
int		stack_len(t_stack *stack);
t_stack	*find_biggest_node(t_stack *stack);
t_stack	*ft_find_penult_node(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);

/* ************************************************************************** */
/*                              stack_utils2                                  */
/* ************************************************************************** */

void	min_on_top(t_stack **sa);
t_stack	*find_min(t_stack *sa);
void	ft_free(t_stack *sa, t_stack *sb, int *data);
int		is_valid_number(char *str, int *j);
int		is_valid_char(char c);

/* ************************************************************************** */
/*                              stack_sort                                    */
/* ************************************************************************** */

bool	is_sorted(t_stack *stack);
void	sort_three(t_stack **stack);
void	stack_sort(t_stack **sa, t_stack **sb);

/* ************************************************************************** */
/*                              stack_push                                    */
/* ************************************************************************** */

void	move_to_sb(t_stack **sa, t_stack **sb);
void	move_to_sa(t_stack **sa, t_stack **sb);
void	rotate_both(t_stack **sa, t_stack **sb, t_stack *cheap);
void	rev_rotate_both(t_stack **sa, t_stack **sb, t_stack *cheap);
void	set_stack(t_stack **stack, t_stack *node, char s_name);

/* ************************************************************************** */
/*                              stack_ops                                     */
/* ************************************************************************** */

void	do_op(t_stack **stack1, t_stack **stack2, t_operation op);
void	reverse_rotate(t_stack **stack, char *str);
void	swap(t_stack **stack, char *str);
void	rotate(t_stack **stack, char *str);
void	push(t_stack **src, t_stack **dest, char *str);

/* ************************************************************************** */
/*                              stack_ops2                                    */
/* ************************************************************************** */

void	rrr(t_stack **sa, t_stack **sb, char *str);
void	rr(t_stack **sa, t_stack **sb, char *str);

#endif