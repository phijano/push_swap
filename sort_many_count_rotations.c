/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many_count_rotations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:20:59 by phijano-          #+#    #+#             */
/*   Updated: 2022/06/30 10:15:21 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

static int	ft_check_room(int length, int *stack_a, int *stack_b, int count_b)
{
	if (stack_a[0] > stack_b[count_b]
		&& stack_a[stack_a[length] - 1] < stack_b[count_b])
	{
		if (count_b <= stack_b[length] / 2)
			return (count_b);
		else
			return (stack_b[length] - count_b);
	}
	return (-2);
}

int	ft_count_rotations(int length, int *stack_a, int *stack_b, int c_b)
{
	int	rot;
	int	c_a;

	rot = ft_check_room(length, stack_a, stack_b, c_b);
	if (rot != -2)
		return (rot);
	c_a = -1;
	while (++c_a < stack_a[length] - 1)
	{
		if (stack_b[c_b] > stack_a[c_a]
			&& stack_b[c_b] < stack_a[c_a + 1])
		{
			if (c_a < stack_a[length] / 2 && c_b <= stack_b[length] / 2)
				rot = ft_big(c_a + 1, c_b);
			else if (c_a >= stack_a[length] / 2 && c_b > stack_b[length] / 2)
				rot = ft_big(stack_a[length] - 1 - c_a, stack_b[length] - c_b);
			else if (c_a < stack_a[length] / 2)
				rot = c_a + 1 + stack_b[length] - c_b;
			else
				rot = stack_a[length] - 1 - c_a + c_b;
			break ;
		}
	}
	return (rot);
}
