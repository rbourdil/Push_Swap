/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:22:49 by rbourdil          #+#    #+#             */
/*   Updated: 2022/05/30 16:05:36 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_moves	moves;

	init_stacks(&a, &b, argc, argv);
	if (argc == 1 || sorted(&a))
	{
		free(a.list);
		free(b.list);
		return (0);
	}
	if (argc <= 6)
	{
		minsort(&a, &b);
		return (0);
	}
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
