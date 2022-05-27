/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:21:54 by rbourdil          #+#    #+#             */
/*   Updated: 2022/05/27 16:02:25 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a >= b)
		return (b);
	return (a);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}
