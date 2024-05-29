/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:35:22 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/05/21 14:35:22 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*add_numbers(char **str, int *nbr)
{
	int	i;
	int	j;
	int	k;

	if (!nbr)
		return (0);
	i = 1;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			while (str[i][j] == ' ' || str[i][j] == '\t' || str[i][j] == '\n')
				j++;
			if (str[i][j])
				nbr[k++] = ft_atoi(&str[i][j]);
			while (ft_isdigit(str[i][j]) || str[i][j] == '+'
				|| str[i][j] == '-')
				j++;
		}
		i++;
	}
	return (nbr);
}

void	init_stack_a(t_stack **stack, int *data, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_add_node(stack, data[i]);
		i++;
	}
}

void	ft_add_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last;

	if (!stack)
		return ;
	node = ft_calloc(1, sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->number = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = find_last_node(*stack);
		last->next = node;
		node->prev = last;
	}
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}

t_stack	*find_last_node(t_stack *stack)
{
	t_stack	*last_node;

	while (stack->next)
		stack = stack->next;
	last_node = stack;
	return (last_node);
}
