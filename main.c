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

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char **pinto;

	a = NULL;
	b = NULL;
	if(argc == 1 || (argc == 2 && !argv[1][0])) {
		return (0);
	}
	if (argc == 2) {
		pinto = ft_split(argv[1], ' ');
		init_stack_a(&a, pinto, argc);
	}
	init_stack_a(&a, argv, argc);
	if (!stack_sorted(a))
	{
		if(ft_stack_len(a) == 2)
			do_op(&a, &b, SA);
		else if(ft_stack_len(a) == 3)
			sort_three(&a);
		//else
	}
	ft_print_test(a, b);
	return (0);
}

void ft_print_test(t_stack *head_a, t_stack *head_b)
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

/*	t_stack	*sa;
	t_stack	*sa1;
	t_stack	*sa2;
	t_stack	*sa3;
	t_stack *head_a;

	t_stack	*sb;
	t_stack	*sb1;
	t_stack	*sb2;
	t_stack	*sb3;
	t_stack *head_b;

	sa = malloc(sizeof(t_stack));
	sa1 = malloc(sizeof(t_stack));
	sa2 = malloc(sizeof(t_stack));
	sa3 = malloc(sizeof(t_stack));

	sb = malloc(sizeof(t_stack));
	sb1 = malloc(sizeof(t_stack));
	sb2 = malloc(sizeof(t_stack));
	sb3 = malloc(sizeof(t_stack));

	head_a = sa;
	head_b = sb;

	sa->number = 10;
	sa->next = sa1;
	sa1->number = 20;
	sa1->next = sa2;
	sa2->number = 30;
	sa2->next = sa3;
	sa3->number = 40;
	sa3->next = NULL;

	sb->number = 50;
	sb->next = sb1;
	sb1->number = 60;
	sb1->next = sb2;
	sb2->number = 70;
	sb2->next = sb3;
	sb3->number = 80;
	sb3->next = NULL;

	do_op(&head_a,&head_b,RRB);

	printf("List a:\n");
	while (head_a)
	{
		printf("%i\n", head_a->number);
		head_a = head_a->next;
	}
	printf("List b:\n");
	while (head_b)
	{
		printf("%i\n", head_b->number);
		head_b = head_b->next;
	}*/