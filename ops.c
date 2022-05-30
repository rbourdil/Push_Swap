/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:23:06 by rbourdil          #+#    #+#             */
/*   Updated: 2022/05/27 17:41:06 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pop(t_stack *stack)
{
	int	i;
	int	ret;

	ret = stack->list[0];
	i = 1;
	while (i < stack->size)
	{
		stack->list[i - 1] = stack->list[i];
		i++;
	}
	stack->size--;
	return (ret);
}

void	push(t_stack *a, t_stack *b)
{
	int	n;
	int	tmp;
	int	i;

	n = pop(b);
	i = 0;
	while (i < a->size)
	{
		tmp = a->list[i];
		a->list[i++] = n;
		n = tmp;
	}
	a->list[i] = n;
	a->size++;
}

void	rotate(t_stack *stack)
{
	int	last;
	int	i;

	last = stack->list[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->list[i] = stack->list[i + 1];
		i++;
	}
	stack->list[i] = last;
}

void	rev_rotate(t_stack *stack)
{
	int	tmp1;
	int	tmp2;
	int	i;

	tmp1 = stack->list[stack->size - 1];
	i = 0;
	while (i < stack->size)
	{
		tmp2 = stack->list[i];
		stack->list[i++] = tmp1;
		tmp1 = tmp2;
	}
}

void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->list[0];
	stack->list[0] = stack->list[1];
	stack->list[1] = tmp;
}
