/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:43:58 by rbourdil          #+#    #+#             */
/*   Updated: 2022/05/30 14:05:18 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	insert_dist(t_stack *stack, int n)
{
	int	dist;
	int	lower;
	int	i;

	lower = MININT;
	dist = 0;
	i = 0;
	while (i < stack->size)
	{
		if (n > stack->list[i] && stack->list[i] > lower)
		{
			dist = i;
			lower = stack->list[i];
		}
		i++;
	}
	if (dist > stack->size / 2)
		return (dist - stack->size);
	return (dist);
}

int	find_max(t_stack *stack)
{
	int	pos;
	int	max;
	int	i;

	pos = 0;
	max = stack->list[0];
	i = 0;
	while (i < stack->size)
	{
		if (stack->list[i] > max)
		{
			pos = i;
			max = stack->list[i];
		}
		i++;
	}
	if (pos > stack->size / 2)
		return (pos - stack->size);
	return (pos);
}

void	min_dist(int dista, int distb, t_moves *moves)
{
	if (dista >= 0 && distb >= 0 && max(dista, distb) < moves->total)
	{
		moves->total = max(dista, distb);
		moves->common = min(dista, distb);
		moves->mode = RR | RA;
		if (dista < distb)
			moves->mode = RR | RB;
	}
	else if (dista <= 0 && distb <= 0 \
		&& ft_abs(min(dista, distb)) < moves->total)
	{
		moves->total = ft_abs(min(dista, distb));
		moves->common = ft_abs(max(dista, distb));
		moves->mode = RRR | RRB;
		if (dista < distb)
			moves->mode = RRR | RRA;
	}
}

void	find_least_moves(t_stack *a, t_stack *b, t_moves *moves)
{
	int	i;
	int	dista;
	int	distb;

	moves->total = a->size + b->size;
	i = 0;
	while (i < a->size)
	{
		dista = i;
		if (i > a->size / 2)
			dista = i - a->size;
		distb = insert_dist(b, a->list[i]);
		if (dista < 0 && distb > 0 && ft_abs(dista) <= ft_abs(distb))
			distb -= b->size;
		else if (dista < 0 && distb > 0)
			dista += a->size;
		else if (dista > 0 && distb < 0 && ft_abs(dista) <= ft_abs(distb))
			distb += b->size;
		else if (dista > 0 && distb < 0)
			dista -= a->size;
		min_dist(dista, distb, moves);
		i++;
	}
}
