/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:50:14 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/05/21 14:50:14 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort_three(t_stack **stack)
{
	t_stack	*biggest_node;

	biggest_node = find_biggest_node(*stack);
	if (biggest_node == *stack)
		do_op(stack, NULL, RA);
	else if ((*stack)->next == biggest_node)
		do_op(stack, NULL, RRA);
	if ((*stack)->data > (*stack)->next->data)
		do_op(stack, NULL, SA);
}

void	stack_sort(t_stack **sa, t_stack **sb)
{
	int	len;

	len = stack_len(*sa);
	if (len-- > 3 && !is_sorted(*sa))
		do_op(sa, sb, PB);
	if (len-- > 3 && !is_sorted(*sa))
		do_op(sa, sb, PB);
	while (len-- > 3 && !is_sorted(*sa))
	{
		init_nodes_sa(*sa, *sb);
		move_to_sb(sa, sb);
	}
	sort_three(sa);
	while (*sb)
	{
		init_nodes_sb(*sa, *sb);
		move_to_sa(sa, sb);
	}
	current_index(*sa);
	min_on_top(sa);
}
