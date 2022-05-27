/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:22:49 by rbourdil          #+#    #+#             */
/*   Updated: 2022/05/27 17:41:47 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_least_moves(t_stack *a, t_stack *b, t_moves *moves)
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

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_moves	moves;

	if (argc == 1)
		return (-1);
	init_stacks(&a, &b, argc, argv);
	exe_ops(&a, &b, PB);
	exe_ops(&a, &b, PB);
	if (b.list[0] < b.list[1])
		exe_ops(&a, &b, RB);
	while (a.size > 0)
	{
		find_least_moves(&a, &b, &moves);
		exec_moves(&a, &b, &moves);
	}
	transfer_b_to_a(&a, &b);
	free(a.list);
	free(b.list);
	return (0);
}
