/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:10:59 by rbourdil          #+#    #+#             */
/*   Updated: 2022/05/27 17:18:01 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	else if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static int	not_int(char *nb)
{
	while (ft_isspace(*nb))
		nb++;
	if (*nb == '+' || *nb == '-')
		nb++;
	while (ft_isdigit(*nb))
		nb++;
	if (*nb != '\0')
		return (1);
	return (0);
}

static int	duplicate(t_stack *stack, int elem, int last)
{
	int	i;

	i = 0;
	while (i < last)
	{
		if (elem == stack->list[i])
			return (1);
		i++;
	}
	return (0);
}

void	init_stacks(t_stack *a, t_stack *b, int argc, char *argv[])
{
	int		i;
	long	tmp;

	a->size = argc - 1;
	a->list = (int *)malloc(sizeof(int) * a->size);
	b->list = (int *)malloc(sizeof(int) * a->size);
	b->size = 0;
	i = 0;
	while (i < a->size)
	{
		tmp = ft_atoi(argv[i + 1]);
		if (not_int(argv[i + 1]) || duplicate(a, tmp, i) \
			|| tmp > MAXINT || tmp < MININT)
		{
			free(a->list);
			free(b->list);
			write(STDERR_FILENO, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		a->list[i] = tmp;
		i++;
	}
}
