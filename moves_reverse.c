/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:00:18 by phijano-          #+#    #+#             */
/*   Updated: 2022/06/30 10:09:42 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

static void	ft_reverse(int length, int *stack)
{
	int	temp;
	int	count;

	temp = stack[stack[length] - 1];
	count = stack[length];
	while (--count > 0)
		stack[count] = stack[count - 1];
	stack[0] = temp;
}

void	ft_rra(int length, int *stack_a, int show)
{
	ft_reverse(length, stack_a);
	if (show)
		write(1, "rra\n", 4);
}

void	ft_rrb(int length, int *stack_b, int show)
{
	ft_reverse(length, stack_b);
	if (show)
		write(1, "rrb\n", 4);
}

void	ft_rrr(int length, int *stack_a, int *stack_b, int show)
{
	ft_reverse(length, stack_a);
	ft_reverse(length, stack_b);
	if (show)
		write(1, "rrr\n", 4);
}
