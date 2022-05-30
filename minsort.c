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

static int	sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->list[i] > stack->list[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	minsort(t_stack *a, t_stack *b)
{
	push_min(a, b, 3);
	while (!sorted(a))
	{
		if (a->list[0] < a->list[1])
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
