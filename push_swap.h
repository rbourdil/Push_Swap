/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:23:18 by rbourdil          #+#    #+#             */
/*   Updated: 2022/05/27 17:42:22 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define MAXINT 2147483647
# define MININT -2147483648

# define RR 0x01
# define RRR 0x02
# define RA 0x04
# define RB 0x08
# define RRA 0x10
# define RRB 0x20
# define PA 0x80
# define PB 0x100

typedef struct s_stack {
	int	*list;
	int	size;
}	t_stack;

typedef struct s_moves {
	int	total;
	int	common;
	int	mode;
}	t_moves;

void	init_stacks(t_stack *a, t_stack *b, int argc, char*argv[]);

void	pop_and_push(t_stack *a, t_stack *b);
void	rotate(t_stack *stack);
void	rev_rotate(t_stack *stack);

void	exe_ops(t_stack *a, t_stack *b, int op);

int		find_max(t_stack *stack);
void	min_dist(int dista, int distb, t_moves *moves);
int		insert_dist(t_stack *stack, int n);

void	exec_moves(t_stack *a, t_stack *b, t_moves *moves);
void	transfer_b_to_a(t_stack *a, t_stack *b);

int		max(int a, int b);
int		min(int a, int b);
int		ft_abs(int n);

#endif
