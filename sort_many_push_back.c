/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many_push_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:15:15 by phijano-          #+#    #+#             */
/*   Updated: 2022/06/30 10:22:33 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

static int	ft_get_room_a(int length, int *stack_a, int *stack_b, int index_b)
{
	int	count_a;
	int	index_a;

	index_a = ft_min(length, stack_a);
	count_a = -1;
	if (stack_a[0] > stack_b[index_b]
		&& stack_a[stack_a[length] - 1] < stack_b[index_b])
		return (0);
	while (++count_a < stack_a[length] - 1)
		if (stack_b[index_b] > stack_a[count_a]
			&& stack_b[index_b] < stack_a[count_a + 1])
			index_a = count_a + 1;
	return (index_a);
}

static void	ft_rot_to_push(int length, int *stack_a, int *stack_b, int index_b)
{
	int	index_a;
	int	number_a;
	int	number_b;

	index_a = ft_get_room_a(length, stack_a, stack_b, index_b);
	number_a = stack_a[index_a];
	number_b = stack_b[index_b];
	while (stack_a[0] != number_a || stack_b[0] != number_b)
	{
		if (index_a <= stack_a[length] / 2 && index_b <= stack_b[length] / 2
			&& stack_a[0] != number_a && stack_b[0] != number_b)
			ft_rr_many(length, stack_a, stack_b, ft_lower(index_a, index_b));
		else if (index_a > stack_a[length] / 2 && index_b > stack_b[length] / 2
			&& stack_a[0] != number_a && stack_b[0] != number_b)
			ft_rrr_many(length, stack_a, stack_b,
				ft_lower(stack_a[length] - index_a, stack_b[length] - index_b));
		if (index_a <= stack_a[length] / 2 && stack_a[0] != number_a)
			ft_ra(length, stack_a, 1);
		else if (index_a > stack_a[length] / 2 && stack_a[0] != number_a)
			ft_rra(length, stack_a, 1);
		if (index_b <= stack_b[length] / 2 && stack_b[0] != number_b)
			ft_rb(length, stack_b, 1);
		else if (index_b > stack_b[length] / 2 && stack_b[0] != number_b)
			ft_rrb(length, stack_b, 1);
	}
}

static void	ft_less_rotates(int length, int *stack_a, int *stack_b)
{
	int	index;
	int	rotations;
	int	best_rotation;
	int	count_b;

	count_b = -1;
	best_rotation = -1;
	index = 0;
	while (++count_b < stack_b[length])
	{
		rotations = ft_count_rotations(length, stack_a, stack_b, count_b);
		if ((rotations < best_rotation || best_rotation == -1)
			&& rotations != -2)
		{
			best_rotation = rotations;
			index = count_b;
		}
	}
	ft_rot_to_push(length, stack_a, stack_b, index);
}

void	ft_push_back(int length, int *stack_a, int *stack_b)
{
	while (stack_b[length] > 0)
	{
		ft_less_rotates(length, stack_a, stack_b);
		ft_pa(length, stack_a, stack_b, 1);
	}
}
