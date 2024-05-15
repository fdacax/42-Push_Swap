/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:17:25 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/05/14 16:17:25 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_b(t_stack *sa, t_stack *sb)
{
	node_index(sa);
	node_index(sb);
	set_target_b_to_a(sa, sb);
}

void	set_target_b_to_a(t_stack *sa, t_stack *sb)
{
	t_stack	*sa_aux;
	t_stack	*target;
	long	max_index;

	while (sb)
	{
		max_index = LONG_MAX;
		sa_aux = sa;
		while (sa_aux)
		{
			if (sa_aux->data > sb->data && sa_aux->data < max_index)
			{
				max_index = sa_aux->data;
				target = sa_aux;
			}
			sa_aux = sa_aux->next;
		}
		if (max_index == LONG_MAX)
			sb->target_node = find_max_data(sa);
		else
			sb->target_node = target;
		sb = sb->next;
	}
}
