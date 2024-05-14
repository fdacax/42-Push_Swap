/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:18:48 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/04/17 19:18:48 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*biggest_node;

	biggest_node = find_max_data(*stack);
	if (biggest_node == *stack)
		do_op(stack, NULL, RA);
	else if((*stack)->next == biggest_node)
		do_op(stack, NULL, RRA);
	if ((*stack)->data > (*stack)->next->data)
		do_op(stack, NULL, SA);
}

t_stack	*find_max_data(t_stack *stack)
{
	long int	max_data;
	t_stack		*max_node;

	max_data = LONG_MIN;
	while (stack)
	{
		if(stack->data > max_data)
		{
			max_data = stack->data;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack *find_min_data(t_stack *stack)
{
	long	min_data;
	t_stack *min_node;

	if(!stack)
		return (NULL);
	min_data = LONG_MAX;
	while (stack)
	{
		if (stack->data < min_data)
		{
			min_data = stack->data;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
