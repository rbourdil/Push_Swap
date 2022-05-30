/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:31:16 by rbourdil          #+#    #+#             */
/*   Updated: 2022/05/27 17:42:43 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_ops(int op)
{
	if ((op & RR) != 0)
		write(STDOUT_FILENO, "rr\n", 3);
	else if ((op & RRR) != 0)
		write(STDOUT_FILENO, "rrr\n", 4);
	else if ((op & RA) != 0)
		write(STDOUT_FILENO, "ra\n", 3);
	else if ((op & RB) != 0)
		write(STDOUT_FILENO, "rb\n", 3);
	else if ((op & RRA) != 0)
		write(STDOUT_FILENO, "rra\n", 4);
	else if ((op & RRB) != 0)
		write(STDOUT_FILENO, "rrb\n", 4);
	else if ((op & PA) != 0)
		write(STDOUT_FILENO, "pa\n", 3);
	else if ((op & PB) != 0)
		write(STDOUT_FILENO, "pb\n", 3);
	else if ((op & SA) != 0)
		write((STDOUT_FILENO), "sa\n", 3);
}

void	exe_ops(t_stack *a, t_stack *b, int op)
{
	if ((op & RR) != 0)
	{
		rotate(a);
		rotate(b);
	}
	else if ((op & RRR) != 0)
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	else if ((op & RA) != 0)
		rotate(a);
	else if ((op & RB) != 0)
		rotate(b);
	else if ((op & RRA) != 0)
		rev_rotate(a);
	else if ((op & RRB) != 0)
		rev_rotate(b);
	else if ((op & PA) != 0)
		push(a, b);
	else if ((op & PB) != 0)
		push(b, a);
	else if ((op & SA) != 0)
		swap(a);
	print_ops(op);
}
