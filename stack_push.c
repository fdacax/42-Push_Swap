/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:00:43 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/05/21 15:00:43 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b(t_stack **sa, t_stack **sb)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*sa);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(sa, sb, cheapest_node);
	else if (!(cheapest_node->above_median)
			 && !(cheapest_node->target_node->above_median))
		rev_rotate_both(sa, sb, cheapest_node);
	prep_for_push(sa, cheapest_node, 'a');
	prep_for_push(sb, cheapest_node->target_node, 'b');
	do_op(sa, sb, PB);
}

void	move_b_to_a(t_stack **sa, t_stack **sb)
{
	prep_for_push(sa, (*sb)->target_node, 'a');
	do_op(sb, sa, PA);
}

void	rotate_both(t_stack **sa, t_stack **sb, t_stack *cheap)
{
	while (*sb != cheap->target_node && *sa != cheap)
		do_op(sa, sb, RR);
	current_index(*sa);
	current_index(*sb);
}

void	rev_rotate_both(t_stack **sa, t_stack **sb, t_stack *cheap)
{
	while (*sb != cheap->target_node && *sa != cheap)
		do_op(sa, sb, RRR);
	current_index(*sa);
	current_index(*sb);
}

void	prep_for_push(t_stack **stack, t_stack *node, char s_name)
{
	while (*stack != node)
	{
		if (s_name == 'a')
		{
			if (node->above_median)
				do_op(stack, NULL, RA);
			else
				do_op(stack, NULL, RRA);
		}
		else if (s_name == 'b')
		{
			if (node->above_median)
				do_op(stack, NULL, RB);
			else
				do_op(stack, NULL, RRB);
		}
	}
}