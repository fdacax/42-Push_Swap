/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:29:45 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/05/21 14:29:45 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*sa;
	t_stack	*sb;
	int		*data;
	int		len;

	len = 0;
	check_errors(argc, argv, &len);
	data = ft_calloc(len, sizeof(int));
	data = add_numbers(argv, data);
	check_duplicate(data, len);
	sa = NULL;
	sb = NULL;
	init_stack_a(&sa, data, len);
	if (!is_sorted(sa))
	{
		if (stack_len(sa) == 2)
			do_op(&sa, &sa, SA);
		else if (stack_len(sa) == 3)
			sort_three(&sa);
		else
			big_sort(&sa, &sb);
	}
	ft_free(sa, sb, data);
	return (0);
}
