/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:25:54 by rbourdil          #+#    #+#             */
/*   Updated: 2022/05/27 15:30:34 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	transfer_b_to_a(t_stack *a, t_stack *b)
{
	int	dist;

	while (b->size > 0)
	{
		dist = find_max(b);
		while (dist > 0)
		{
			exe_ops(a, b, RB);
			dist--;
		}
		while (dist < 0)
		{
			exe_ops(a, b, RRB);
			dist++;
		}
		exe_ops(a, b, PA);
	}
}

void	exec_moves(t_stack *a, t_stack *b, t_moves *moves)
{
	while (moves->common-- > 0)
	{
		if ((moves->mode & RR) != 0)
			exe_ops(a, b, RR);
		else if ((moves->mode & RRR) != 0)
			exe_ops(a, b, RRR);
		moves->total--;
	}
	while (moves->total-- > 0)
	{
		if ((moves->mode & RA) != 0)
			exe_ops(a, b, RA);
		else if ((moves->mode & RB) != 0)
			exe_ops(a, b, RB);
		else if ((moves->mode & RRA) != 0)
			exe_ops(a, b, RRA);
		else if ((moves->mode & RRB) != 0)
			exe_ops(a, b, RRB);
	}
	exe_ops(a, b, PB);
}
