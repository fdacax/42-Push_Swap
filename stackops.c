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

}

void	ft_swap(t_stack **stack, char *str)
{
	t_stack	*aux;
	// Lista valor (40 e 30)
	aux = (*stack)->next; // aux aponta para o 2º nó (valor 30)
	(*stack)->next = aux->next; // stack->next aponta para o proximo nó de aux
	aux->next = (*stack); // aux->next aponta para o primeiro nó da lista (valor 40)
	(*stack) = aux; // stack aponta para aux que tem o valor original de stack->next voltando ao inicio da lista (com os valores 30, 40)
}
