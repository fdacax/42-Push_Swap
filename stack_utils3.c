/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:47:28 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/05/14 16:47:28 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_a(t_stack **sa, t_stack **sb)
{
	prep_for_push(sa, (*sb)->target_node, 'a');
	do_op(sb, sa, PA);
}

void	check_stack( t_stack **sa)
{
	while ((*sa)->data != find_min_data(*sa)->data)
	{
		if (find_min_data((*sa))->above_median)
			do_op(sa, NULL, RA);
		else
			do_op(sa, NULL, RRA);
	}
}
