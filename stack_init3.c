/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:06:56 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/05/21 15:06:56 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_nodes_sb(t_stack *sa, t_stack *sb)
{
	current_index(sa);
	current_index(sb);
	set_target_to_sa(sa, sb);
}

void	set_target_to_sa(t_stack *sa, t_stack *sb)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_index;

	while (sb)
	{
		best_index = LONG_MAX;
		current_a = sa;
		while (current_a)
		{
			if (current_a->data > sb->data
				&& current_a->data < best_index)
			{
				best_index = current_a->data;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_index == LONG_MAX)
			sb->target_node = find_min(sa);
		else
			sb->target_node = target_node;
		sb = sb->next;
	}
}
