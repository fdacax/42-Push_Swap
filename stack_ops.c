/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:14:12 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/05/21 15:14:12 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_op(t_stack **stack1, t_stack **stack2, t_operation op)
{
	if (op == SA)
		return (swap(stack1, "sa"));
	else if (op == SB)
		return (swap(stack1, "sb"));
	else if (op == PA)
		return (push(stack1, stack2, "pa"));
	else if (op == PB)
		return (push(stack1, stack2, "pb"));
	else if (op == RA)
		return (rotate(stack1, "ra"));
	else if (op == RB)
		return (rotate(stack1, "rb"));
	else if (op == RR)
		return (rr(stack1, stack2, "rr"));
	else if (op == RRA)
		return (reverse_rotate(stack1, "rra"));
	else if (op == RRB)
		return (reverse_rotate(stack1, "rrb"));
	else if (op == RRR)
		return (rrr(stack1, stack2, "rrr"));
}

void	reverse_rotate(t_stack **stack, char *str)
{
	t_stack	*helper;
	t_stack	*last;
	int		size;
	int		i;

	last = find_last_node(*stack);
	helper = *stack;
	shift_stack(*stack);
	size = stack_len(*stack);
	i = 0;
	while (i < size - 1)
	{
		if (i == size - 2)
			helper->next = NULL;
		helper = helper->next;
		i++;
	}
	last->next = *stack;
	*stack = last;
	if (str)
		ft_putendl_fd(str, 1);
}

void	swap(t_stack **stack, char *str)
{
	t_stack	*aux;

	aux = (*stack)->next;
	(*stack)->next = aux->next;
	aux->next = (*stack);
	(*stack) = aux;
	if (str)
		ft_putendl_fd(str, 1);
}

void	rotate(t_stack **stack, char *str)
{
	t_stack	*helper;
	t_stack	*last_node;
	t_stack	*sec;

	helper = *stack;
	last_node = find_last_node(*stack);
	sec = (*stack)->next;
	shift_stack(*stack);
	(*stack) = sec;
	last_node->next = helper;
	helper->next = NULL;
	if (str)
		ft_putendl_fd(str, 1);
}

void	push(t_stack **src, t_stack **dest, char *str)
{
	t_stack	*helper;

	helper = *src;
	if (stack_len(*src) == 0)
		return ;
	shift_stack(*src);
	shift_stack(*dest);
	*src = (*src)->next;
	helper->next = *dest;
	*dest = helper;
	if (str)
		ft_putendl_fd(str, 1);
}
