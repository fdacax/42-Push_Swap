/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:31:02 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/04/15 20:14:13 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_op(t_stack **sa, t_stack **sb, t_ops op)
{
	if (op == SA)
		return (ft_swap(sa, "sa"));
	else if (op == SB)
		return (ft_swap(sb, "sb"));
	else if (op == PA)
		return (ft_push(sa, sb, "pa"));
	else if (op == PB)
		return (ft_push(sa, sb, "pb"));
	else if (op == RA)
		return (ft_rotate(sa, "ra"));
	else if (op == RB)
		return (ft_rotate(sb, "rb"));
	else if (op == RRA)
		return (ft_reverse_rotate(sa, "rra"));
	else if (op == RRB)
		return (ft_reverse_rotate(sb, "rrb"));
	else if (op == RR)
		return (ft_rr(sa, sb, "rr"));
	else if (op == RRR)
		return (ft_rrr(sa, sb, "rrr"));
}

void	ft_swap(t_stack **stack, char *str)
{
	t_stack	*aux;
	// Lista valor (40 e 30, 20)
	aux = (*stack)->next; // aux aponta para o 2º nó (valor 30)
	(*stack)->next = aux->next; // stack->next aponta para o proximo nó de aux(valor 20)
	aux->next = (*stack); // aux->next aponta para o primeiro nó da lista (valor 40)
	(*stack) = aux; // volta ao inicio da lista (com os valores 30, 40,20)
	if (str)
		ft_putendl_fd(str, 1);
}

void	ft_push(t_stack **stack1, t_stack **stack2, char *str)
{
	t_stack	*aux;

	aux = *stack1;
	ft_shift_stack(*stack1);
	ft_shift_stack(*stack2);
	*stack1 = (*stack1)->next;
	aux->next = *stack2;
	*stack2 = aux;
	if (str)
		ft_putendl_fd(str, 1);
}

void	ft_rotate(t_stack **stack, char *str)
{
	t_stack	*aux;
	t_stack	*head;

	aux = (*stack); // aux aponta para o n1 da lista
	(*stack) = (*stack)->next; // o n1 agora vira n2
	head = (*stack); //o meu head aponta para o inicio da stack
	(*stack) = ft_find_last_node(*stack);// last aponta para o ultimo no da stack
	(*stack)->next = aux; // pega meu n1 e coloca a seguir do ultimo
	aux->next = NULL; // defino como ultimo
	(*stack) = head; // volto ao inicio
	if (str)
		ft_putendl_fd(str, 1);
}

void	ft_reverse_rotate(t_stack **stack, char *str)
{
	t_stack	*last;
	t_stack	*aux;

	last = ft_find_penult_node(*stack);
	aux = ft_find_last_node(*stack);
	aux->next = *stack;
	last->next = NULL;
	(*stack) = aux;
	if (str)
		ft_putendl_fd(str, 1);
}
