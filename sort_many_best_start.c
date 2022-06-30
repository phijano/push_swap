/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many_best_start.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:26:50 by phijano-          #+#    #+#             */
/*   Updated: 2022/06/30 10:15:01 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

static int	ft_get_limit(int length)
{
	int	limit;

	limit = 20;
	if (length <= 20)
		limit = 2;
	else if (length > 20 && length <= 50)
		limit = 5;
	else if (length > 50 && length < 300)
		limit = 15;
	return (limit);
}

int	ft_best_start(int length, int *stack_a)
{
	int	best;
	int	number;
	int	start;
	int	index;
	int	limit_test;

	number = -1;
	best = -1;
	limit_test = ft_get_limit(length);
	while (++number < limit_test)
	{
		index = ft_get_index(length, stack_a, number);
		if (best == -1)
		{
			best = ft_lower(index, length - index);
			start = index;
		}
		else
		{
			best = ft_lower(best, ft_lower(index, length - index));
			if (best == index || best == length - index)
				start = index;
		}
	}
	return (start);
}
