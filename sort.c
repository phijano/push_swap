/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:48:38 by phijano-          #+#    #+#             */
/*   Updated: 2022/06/30 10:12:32 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

int	ft_is_sorted(int length, int *stack_a)
{
	int	count;

	count = -1;
	while (++count < length - 1)
	{
		if (stack_a[count] > stack_a[count + 1])
			return (0);
	}
	return (1);
}

static void	ft_sort_three(int length, int *stack_a)
{
	int	sorted;

	sorted = ft_is_sorted(length, stack_a);
	if (!sorted)
	{
		if (length == 2)
			write(1, "sa\n", 3);
		else
		{
			if (stack_a[0] > stack_a[1] && stack_a[0]
				> stack_a[2] && stack_a[1] > stack_a[2])
				write(1, "ra\nsa\n", 6);
			else if (stack_a[0] > stack_a[1] && stack_a[0]
				> stack_a[2] && stack_a[1] < stack_a[2])
				write(1, "ra\n", 3);
			else if (stack_a[0] < stack_a[1] && stack_a[2]
				< stack_a[1] && stack_a[0] > stack_a[2])
				write(1, "rra\n", 4);
			else if (stack_a[0] < stack_a[1] && stack_a[2]
				< stack_a[1] && stack_a[0] < stack_a[2])
				write(1, "rra\nsa\n", 7);
			else
				write(1, "sa\n", 3);
		}
	}
}

static void	ft_sort_five(int length, int *stack_a, int *stack_b)
{
	int	sorted;
	int	number_of_push;

	sorted = ft_is_sorted(length, stack_a);
	if (!sorted)
	{
		number_of_push = length - 3;
		while (number_of_push-- > 0)
			ft_push_lowest(length, stack_a, stack_b);
		ft_sort_three(stack_a[length], stack_a);
		number_of_push = length - 3;
		while (number_of_push-- > 0)
			ft_pa(length, stack_a, stack_b, 1);
	}
}

static void	ft_sort_many(int length, int *stack_a, int *stack_b)
{
	int	sorted;
	int	start;

	sorted = ft_is_sorted(length, stack_a);
	if (!sorted)
	{
		start = ft_best_start(length, stack_a);
		ft_sort_many_alg(length, stack_a, stack_b, start);
	}
}

int	*ft_sort(int length, int *stack_a)
{
	int	*stack_b;

	stack_b = (int *)malloc(sizeof(*stack_b) * (length + 1));
	if (!stack_b)
		return (NULL);
	else
		stack_b[length] = 0;
	if (length <= 5)
		ft_sort_five(length, stack_a, stack_b);
	else
		ft_sort_many(length, stack_a, stack_b);
	free(stack_b);
	return (stack_a);
}
