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
	while ((*sa)->data != find_min(*sa)->data)
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

	min = sa->data;
	while (sa)
	{
		if (sa->data <= min)
		{
			min_node = sa;
			min = sa->data;
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

int	is_valid_number(char *str, int *j)
{
	while (str[*j] == '-' || str[*j] == '+' || ft_isdigit(str[*j]))
	{
		if (ft_isdigit(str[*j]) && (str[*j + 1] == '-' || str[*j + 1] == '+'))
			return (0);
		(*j)++;
	}
	return (1);
}

int	is_valid_char(char c)
{
	if (c != ' ' && c != '\t' && !ft_isdigit(c) && c != '+' && c != '-')
		return (0);
	return (1);
}
