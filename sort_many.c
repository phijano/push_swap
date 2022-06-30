/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:10:05 by phijano-          #+#    #+#             */
/*   Updated: 2022/06/30 10:14:18 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

static void	ft_rotate_start(int length, int *stack_a, int start)
{
	int	count;

	count = -1;
	if (start <= length / 2)
		while (++count < start)
			ft_ra(length, stack_a, 1);
	else
		while (++count < length - start)
			ft_rra(length, stack_a, 1);
}

static int	ft_rotate_if_not_pushed(int length, int *stack_a, int pushed)
{
	if (pushed == 0)
		ft_ra(length, stack_a, 1);
	else
		pushed = 0;
	return (pushed);
}

static void	ft_rotate_lower_top(int length, int *stack_a)
{
	int	index;

	index = ft_min(length, stack_a);
	while (stack_a[0] != 0)
	{
		if (index <= stack_a[length] / 2)
			ft_ra(length, stack_a, 1);
		else
			ft_rra(length, stack_a, 1);
	}
}

void	ft_sort_many_alg(int length, int *stack_a, int *stack_b, int start)
{
	int	count;
	int	pushed;

	ft_rotate_start(length, stack_a, start);
	count = 0;
	pushed = 0;
	while (++count < length)
	{
		pushed = ft_rotate_if_not_pushed(length, stack_a, pushed);
		pushed = ft_swap_push(length, stack_a, stack_b, pushed);
	}
	ft_push_back(length, stack_a, stack_b);
	ft_rotate_lower_top(length, stack_a);
}
