/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:19:26 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/04/15 20:17:41 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_shift_stack(t_stack *stack)
{
	while (stack)
		stack = stack->next;
}

t_stack	*ft_find_last_node(t_stack *stack)
{
	t_stack *last_node;

	last_node = stack;
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}

t_stack	*ft_find_penult_node(t_stack *stack)
{
	t_stack *last_node;

	last_node = stack;
	while (last_node->next->next)
		last_node = last_node->next;
	return (last_node);
}
