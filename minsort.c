/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:05:26 by rbourdil          #+#    #+#             */
/*   Updated: 2022/05/30 15:54:42 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_stack *stack)
{
	int	i;
	int	min;
	int	dist;

	min = stack->list[0];
	dist = 0;
	i = 0;
	while (i < stack->size)
	{
		if (stack->list[i] < min)
		{
			min = stack->list[i];
			dist = i;
		}
		i++;
	}
	if (dist > stack->size / 2)
		return (dist - stack->size);
	return (dist);
}

static void	push_min(t_stack *a, t_stack *b, int size_left)
{
	int	dist;

	while (a->size > size_left)
	{
		dist = find_min(a);
		while (dist > 0)
		{
			exe_ops(a, b, RA);
			dist--;
		}
		while (dist < 0)
		{
			exe_ops(a, b, RRA);
			dist++;
		}
		exe_ops(a, b, PB);
	}
}

void	minsort(t_stack *a, t_stack *b)
{
	push_min(a, b, 3);
	while (!sorted(a))
	{
		if (a->size < 3)
			exe_ops(a, b, SA);
		else if (a->list[0] < a->list[1])
			exe_ops(a, b, RRA);
		else if (a->list[0] > a->list[1] && a->list[0] < a->list[2])
			exe_ops(a, b, SA);
		else if (a->list[0] > a->list[1] && a->list[0] > a->list[2])
			exe_ops(a, b, RA);
	}
	while (b->size > 0)
		exe_ops(a, b, PA);
	free(a->list);
	free(b->list);
}
