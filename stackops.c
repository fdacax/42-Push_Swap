/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:31:02 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/04/10 18:31:02 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_op(t_stack **sa, t_stack **sb, t_ops op)
{
	if (op == SA)
		return (ft_swap(sa, "sa"));
	if (op == SB)
		return (ft_swap(sb, "sb"));
	if(op == PA)
		return (ft_push(sa, sb, "pa"));
	if(op == PB)
		return (ft_push(sa, sb, "pb"));
	if(op == RA)
		return (ft_rotate(sa, "ra"));
	if (op == RB)
		return (ft_rotate(sb, "rb"));
}

void	ft_swap(t_stack **stack, char *str)
{
	t_stack	*aux;
	// Lista valor (40 e 30, 20)
	aux = (*stack)->next; // aux aponta para o 2º nó (valor 30)
	(*stack)->next = aux->next; // stack->next aponta para o proximo nó de aux(valor 20)
	aux->next = (*stack); // aux->next aponta para o primeiro nó da lista (valor 40)
	(*stack) = aux; // stack aponta para aux que tem o valor original de stack->next voltando ao inicio da lista (com os valores 30, 40)
	ft_printf(str);
}

void ft_push(t_stack **stack1, t_stack **stack2, char *str)
{
	// s1(10, 20, 30)  s2(40, 50, 60)
	t_stack *aux;

	aux = *stack1;
	shift_stack(*stack1);
	shift_stack(*stack2);
	*stack1 = (*stack1)->next;
	aux->next = *stack2;
	*stack2 = aux;
	if (str)
		ft_putendl_fd(str, 1);

}

void ft_rotate(t_stack **stack, char *str)
{

}