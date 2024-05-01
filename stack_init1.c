/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:57:49 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/05/01 15:57:49 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_index(t_stack *stack)
{
	int	i;
	int	half_stack;

	if(!stack)
		return ;
	i = 0;
	half_stack = ft_stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if(i <= half_stack)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_a_to_b(t_stack *sa, t_stack *sb)
{
	t_stack	*sb_aux;
	t_stack	*target;
	long	 min_index;

	while (sa)
	{
		min_index = LONG_MIN;
		sb_aux = sb;
		while (sb_aux)
		{
			if(sb_aux->data < sa->data && sb_aux->data > min_index)
			{
				min_index = sb_aux->data;
				target = sb_aux;
			}
			sb_aux = sb_aux->next;
		}
		if (min_index == LONG_MIN)
			sa->target_node = find_max_data(b);
		else
			sa->target_node = target;
		sa = sa->next;

	}
}

static void	set_cost_to_b(t_stack *sa, t_stack *sb)
{
	int len_sa;
	int	len_sb;

	len_sa = ft_stack_len(sa);
	len_sb = ft_stack_len(sb);
	while (sa)
	{
		sa->cost = sa->index;
		if(!(sa->above_median))
			sa->cost = len_sa - (sa->index);
		if(sa->above_median)
			sa->cost += sa->target_node->index;
		else
			sa->cost += len_sb - (sa->target_node->index);
		sa = sa->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long 	max_long;
	t_stack	*cheapest_node;
	if (!stack)
		return ;
	max_long = LONG_MAX;
	while (stack)
	{
		if(stack->cost < max_long)
		{
			max_long = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;

}
void	init_nodes_a(t_stack *sa, t_stack *sb)
{
	node_index(sa);
	node_index(sb);
	set_target_a_to_b(sa, sb);
	set_cost_to_b(sa, sb);
	set_cheapest(sa);
}
