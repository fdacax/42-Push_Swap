/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:31:29 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/05/21 14:31:29 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit (1);
}

void	check_errors(int argc, char **argv, int *len)
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		ft_print_error();
	if (!check_numbers(argv))
		ft_print_error();
	if (!check_arg(argv, len))
		ft_print_error();
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
			if ((input[i][j] == '+' || input[i][j] == '-')
				&& !(ft_isdigit(input[i][j + 1])))
				return (0);
			if (!is_valid_char(input[i][j]))
				return (0);
			if (ft_isdigit(input[i][j]))
				flag_number = true;
			j++;
		}
		i++;
	}
	if (!flag_number)
		exit (1);
	return (1);
}

int	check_arg(char **str, int *len)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			while (str[i][j] == ' ' || str[i][j] == '\t')
				j++;
			if (str[i][j])
			{
				if (ft_atoi(&str[i][j]) != ft_atol(&str[i][j]))
					return (0);
				*len += 1;
			}
			if (!check_number(str[i], &j))
				return (0);
		}
		i++;
	}
	return (1);
}

void	check_duplicate(int *nbr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (nbr[i] == nbr[j])
			{
				free(nbr);
				ft_print_error();
			}
			j++;
		}
		i++;
	}
}
