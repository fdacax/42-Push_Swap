/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:10:44 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/05/14 18:10:44 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_stack **sa, t_stack **sb, char *str)
{
	str = NULL;
	ft_reverse_rotate(sa, str);
	ft_reverse_rotate(sb, str);
	str = "rrr";
	ft_putendl_fd(str, 1);
}

void	ft_rr(t_stack **sa, t_stack **sb, char *str)
{
	str = NULL;
	ft_rotate(sa, str);
	ft_rotate(sb, str);
	str = "rr";
	ft_putendl_fd(str, 1);
}