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
	int				number;
	int				index;
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}		t_stack;

/* ************************************************************************** */
/*                                   StackOps                                 */
/* ************************************************************************** */

void	do_op(t_stack **sa, t_stack **sb, t_ops op);
void	ft_swap(t_stack **stack, char *str);
void	ft_push(t_stack **stack1, t_stack **stack2, char *str);
void	ft_rotate(t_stack **stack, char *str);
void	ft_reverse_rotate(t_stack **stack, char *str);

/* ************************************************************************** */
/*                                   list_utils                               */
/* ************************************************************************** */

void	ft_shift_stack(t_stack *stack);
t_stack	*ft_find_last_node(t_stack *stack);
t_stack	*ft_find_penult_node(t_stack *stack);


#endif
