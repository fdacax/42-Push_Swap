/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:59:49 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/04/30 15:59:49 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_sort(t_stack **sa, t_stack **sb)
{
	int	len;

	len = ft_stack_len(*sa);
	if (len-- > 3 && !stack_sorted(*sa))
		do_op(sa, sb, PB);
	if (len -- > 3 && !stack_sorted(*sa))
		do_op(sa, sb, PB);
	while (len-- > 3 && !stack_sorted(*sa))
	{
		init_nodes_a(*sa, *sb);
		move_to_b(sa,sb);
	}
	sort_three(sa);
}

void	move_to_b(t_stack **sa, t_stack **sb)
{
	t_stack	*cheapest;

	cheapest = cheapest(*a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		ft_rotate_both(sa, sb, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
		ft_r_rotate_both(sa, sb, cheapest);
	prep_for_push(sa, cheapest, 'a');
	prep_for_push(sb, cheapest->target_node, 'b');
	do_op(sa, sb, PB);


}

t_stack	cheapest_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while(stack)
	{
		if(stack->cheapest)
			return (stack);
		stack = stack->next
	}
}

void	ft_rotate_both(t_stack **sa, t_stack **sb, t_stack *cheapest_node)
{
	while (*sb != cheapest_node->target_node && *a != cheapest_node)
		do_op(sa, sb, RR);
	node_index(*a);
	node_index(*b);
}

void ft_r_rotate_both(t_stack **sa, t_stack **sb, t_stack *cheapest_node)
{
	while (*sb != cheapest_node->target_node && *sa != cheapest_node)
		do_op(sa, sb, RRR);
	node_index(*sa);
	node_index(*sb);

}

void prep_for_push(t_stack **stack, t_stack *node, char name)
{
	while (*stack != node)
	{
		if (name == 'a')
		{
			if (node ->above_median)
				do_op(stack, NULL, RA);
			else
				do_op(stack, NULL, RRA);
		}
		else if (name == 'b')
		{
			if (node->above_median)
				do_op(stack, NULL, RB);
			else
				do_op(stack, NULL, RB);
		}
	}
}