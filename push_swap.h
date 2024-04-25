/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:06:36 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/03/19 17:06:36 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef enum ops
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
}			t_ops;

typedef struct s_stack
{
	int				index;
	int				data;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target_node;
}		t_stack;

void ft_print_test(t_stack *head_a, t_stack *head_b);

/* ************************************************************************** */
/*                                   Stack_init                               */
/* ************************************************************************** */

void	init_stack_a(t_stack **stack, char **argv, int argc);
long	ft_atol(const char *str);
void	ft_add_node(t_stack **stack, int n);
void	ft_one_argc(t_stack **stack, char **str);

/* ************************************************************************** */
/*                                   Stack_ops                                */
/* ************************************************************************** */

void		do_op(t_stack **sa, t_stack **sb, t_ops op);
void		ft_swap(t_stack **stack, char *str);
void		ft_push(t_stack **stack1, t_stack **stack2, char *str);
void		ft_rotate(t_stack **stack, char *str);
void		ft_reverse_rotate(t_stack **stack, char *str);

/* ************************************************************************** */
/*                                   Stack_utils                              */
/* ************************************************************************** */

int			ft_stack_len(t_stack *stack);
bool		stack_sorted(t_stack *stack);
void		ft_shift_stack(t_stack *stack);
t_stack		*ft_find_last_node(t_stack *stack);
t_stack		*ft_find_penult_node(t_stack *stack);
void		sort_three(t_stack **stack);
t_stack		*find_max_data(t_stack *stack);

/* ************************************************************************** */
/*                                   Stack_error                              */
/* ************************************************************************** */

void		ft_print_error(char *error);
int			check_duplicate(char **argv);
int			check_numbers(char **argv);
int			check_arg(char **str);

#endif
