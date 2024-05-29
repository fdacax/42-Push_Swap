/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:45:25 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/05/21 14:45:25 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_stack(t_stack *popped)
{
	while (popped)
		popped = popped->next;
}

int	stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_stack	*find_biggest_node(t_stack *stack)
{
	int		big_number;
	t_stack	*big_node;

	big_number = stack->number;
	while (stack)
	{
		if (stack->number >= big_number)
		{
			big_node = stack;
			big_number = stack->number;
		}
		stack = stack->next;
	}
	return (big_node);
}

t_stack	*ft_find_penult_node(t_stack *stack)
{
	t_stack	*last_node;

	last_node = stack;
	while (last_node->next->next)
		last_node = last_node->next;
	return (last_node);
}

t_stack	*get_cheapest(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}
