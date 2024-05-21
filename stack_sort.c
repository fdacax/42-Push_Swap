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
		if (stack->number > stack->next->number)
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
	if ((*stack)->number > (*stack)->next->number)
		do_op(stack, NULL, SA);
}

void	big_sort(t_stack **sa, t_stack **sb)
{
	int	len_a;

	len_a = stack_len(*sa);
	if (len_a-- > 3 && !is_sorted(*sa))
		do_op(sa, sb, PB);
	if (len_a-- > 3 && !is_sorted(*sa))
		do_op(sa, sb, PB);
	while (len_a-- > 3 && !is_sorted(*sa))
	{
		init_nodes_a(*sa, *sb);
		move_a_to_b(sa, sb);
	}
	sort_three(sa);
	while (*sb)
	{
		init_nodes_b(*sa, *sb);
		move_b_to_a(sa, sb);
	}
	current_index(*sa);
	min_on_top(sa);
}