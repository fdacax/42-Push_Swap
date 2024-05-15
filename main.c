/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:59:00 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/04/10 16:59:00 by fdacax-m         ###   ########.fr       */
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
	ft_check_errors(argc, argv, &len);
	data = ft_calloc(len, sizeof(int));
	data = ft_add_number(argv, data);
	check_duplicate(data, len);
	sa = NULL;
	sb = NULL;
	init_stack_a(&sa, data, len);
	if (!stack_sorted(sa))
	{
		if (ft_stack_len(sa) == 2)
			do_op(&sa, &sa, SA);
		else if (ft_stack_len(sa) == 3)
			sort_three(&sa);
		else
			stack_sort(&sa, &sa);
	}
	ft_print_test(sa, sb);
	return (0);
}

void	ft_print_test(t_stack *head_a, t_stack *head_b)
{
	printf("List a:\n");
	while (head_a)
	{
		printf("%i\n", head_a->data);
		head_a = head_a->next;
	}
	printf("List b:\n");
	while (head_b)
	{
		printf("%i\n", head_b->data);
		head_b = head_b->next;
	}
}
