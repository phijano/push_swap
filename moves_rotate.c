/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:57:50 by phijano-          #+#    #+#             */
/*   Updated: 2022/06/30 10:10:05 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

static void	ft_rotate(int length, int *stack)
{
	int	temp;
	int	count;

	temp = stack[0];
	count = 0;
	while (++count < stack[length])
		stack[count - 1] = stack[count];
	stack[count - 1] = temp;
}

void	ft_ra(int length, int *stack_a, int show)
{
	ft_rotate(length, stack_a);
	if (show)
		write(1, "ra\n", 3);
}

void	ft_rb(int length, int *stack_b, int show)
{
	ft_rotate(length, stack_b);
	if (show)
		write(1, "rb\n", 3);
}

void	ft_rr(int length, int *stack_a, int *stack_b, int show)
{
	ft_rotate(length, stack_a);
	ft_rotate(length, stack_b);
	if (show)
		write(1, "rr\n", 3);
}
