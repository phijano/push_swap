/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:14:30 by phijano-          #+#    #+#             */
/*   Updated: 2022/06/30 10:06:03 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

static int	ft_get_next_index(int index, int length, int *stack_a)
{
	int	count;
	int	next_index;

	count = -1;
	next_index = index;
	while (++count < length)
	{
		if (stack_a[count] > stack_a[index])
		{
			if (index == next_index)
				next_index = count;
			else if (stack_a[count] < stack_a[next_index])
				next_index = count;
		}
	}
	return (next_index);
}

int	*ft_convert_index(int length, int *stack_a)
{
	int	count;
	int	index;
	int	*stack_new;

	stack_new = (int *)malloc(sizeof(*stack_new) * (length) + 1);
	if (!stack_new)
	{
		free(stack_a);
		exit(-1);
	}
	count = -1;
	index = ft_min(length, stack_a);
	while (++count < length)
	{
		stack_new[index] = count;
		index = ft_get_next_index(index, length, stack_a);
	}
	stack_new[length] = length;
	free(stack_a);
	return (stack_new);
}
