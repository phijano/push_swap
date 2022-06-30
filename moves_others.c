/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_others.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:13:37 by phijano-          #+#    #+#             */
/*   Updated: 2022/06/29 13:58:12 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

int	ft_min(int length, int *stack)
{
	int	count;
	int	min_index;
	int	min;

	count = 0;
	min = stack[count];
	min_index = 0;
	while (++count < stack[length])
	{
		if (stack[count] < min)
		{
			min = stack[count];
			min_index = count;
		}
	}
	return (min_index);
}

void	ft_push_lowest(int length, int *stack_a, int *stack_b)
{
	int	is_pushed;
	int	index_min;

	is_pushed = 0;
	while (!is_pushed)
	{
		index_min = ft_min(length, stack_a);
		if (index_min == 0)
		{
			ft_pb(length, stack_a, stack_b, 1);
			is_pushed = 1;
		}
		else if (index_min <= length / 2)
			ft_ra(length, stack_a, 1);
		else
			ft_rra(length, stack_a, 1);
	}
}

void	ft_rr_many(int length, int *stack_a, int *stack_b, int amount)
{
	int	count;

	count = -1;
	while (++count < amount)
		ft_rr(length, stack_a, stack_b, 1);
}

void	ft_rrr_many(int length, int *stack_a, int *stack_b, int amount)
{
	int	count;

	count = -1;
	while (++count < amount)
		ft_rrr(length, stack_a, stack_b, 1);
}
