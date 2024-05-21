/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:16:23 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/05/21 15:16:23 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **sa, t_stack **sb, char *str)
{
	str = NULL;
	rrx(sa, str);
	rrx(sb, str);
	str = "rrr";
	ft_putendl_fd(str, 1);
}

void	rr(t_stack **sa, t_stack **sb, char *str)
{
	str = NULL;
	rx(sa, str);
	rx(sb, str);
	str = "rr";
	ft_putendl_fd(str, 1);
}