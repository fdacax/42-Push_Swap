/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:07:11 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/04/24 20:07:11 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_error(char *error)
{
	ft_putendl_fd(error, 2);
	exit (1);
}

int	check_duplicate(char **argv)
{
	int	i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (0);
			j++;
		}
	i++;
	}
	return (1);
}

int	check_numbers(char **input)
{
	int		i;
	int		j;
	bool	flag_number;

	i = 1;
	flag_number = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if ((input[i][j] == '-' ||input[i][j] == '+')  && !(ft_isdigit(input[i][j + 1])))
				return (0);
			if (input[i][j] != ' ' && input[i][j] != '\t'
				&& !(ft_isdigit(input[i][j])) && input[i][j] != '-' && input[i][j] != '+')
				return (0);
			if (ft_isdigit(input[i][j]))
				flag_number = true;
			j++;
		}
		i++;
	}
	if (!flag_number)
		return (0);
	return (1);
}

int check_arg(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			while (str[i][j] == ' ' || str[i][j] == '\t')
					j++;
			while ((str[i][j] == '-') || (str[i][j] == '+') || (ft_isdigit(str[i][j])))
			{
				if ((ft_isdigit(str[i][j])) && (str[i][j + 1] == '-' || str[i][j + 1] == '+'))
					return (0);
				j++;
			}
			j++;
		}
		i++;
	}
	return (1);
}
