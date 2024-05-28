/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:12:40 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/05/21 15:12:40 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	min_on_top(t_stack **sa)
{
	while ((*sa)->number != find_min(*sa)->number)
	{
		if (find_min(*sa)->above_median)
			do_op(sa, NULL, RA);
		else
			do_op(sa, NULL, RRA);
	}
}

t_stack	*find_min(t_stack *sa)
{
	t_stack	*min_node;
	int		min;

	min = sa->number;
	while (sa)
	{
		if (sa->number <= min)
		{
			min_node = sa;
			min = sa->number;
		}
		sa = sa->next;
	}
	return (min_node);
}

void	ft_free(t_stack *sa, t_stack *sb, int *data)
{
	t_stack	*aux;

	aux = sa;
	while (aux)
	{
		aux = sa->next;
		free(sa);
		sa = aux;
	}
	aux = sb;
	while (aux)
	{
		aux = sb->next;
		free(sb);
		sb = aux;
	}
	free(data);
}