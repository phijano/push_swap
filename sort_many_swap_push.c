/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many_swap_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:20:03 by phijano-          #+#    #+#             */
/*   Updated: 2022/06/30 10:19:36 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

static int	ft_push_if_bad(int length, int *stack_a, int *stack_b)
{
	int	count_next;
	int	pushed;

	pushed = 0;
	count_next = 0;
	while (++count_next <= (stack_a[0] - stack_a[stack_a[length] - 1]) * 3 / 4
		&& stack_a[count_next] != 0)
	{
		if (stack_a[count_next] < stack_a[0])
		{
			ft_pb(length, stack_a, stack_b, 1);
			pushed = 1;
			break ;
		}
	}
	return (pushed);
}

static void	ft_double_swap(int length, int *stack_a)
{
	ft_sa(stack_a, 1);
	ft_rra(length, stack_a, 1);
	ft_sa(stack_a, 1);
	ft_ra(length, stack_a, 1);
}

int	ft_swap_push(int length, int *stack_a, int *stack_b, int pushed)
{
	if (stack_a[0] > stack_a[stack_a[length] - 1])
	{
		if (stack_a[1] < stack_a[0])
		{
			if (stack_a[stack_a[length] - 1] < stack_a[1])
				ft_sa(stack_a, 1);
			else if (stack_a[stack_a[length] - 2] < stack_a[1])
				ft_double_swap(length, stack_a);
		}
		else
			pushed = ft_push_if_bad(length, stack_a, stack_b);
	}
	else
	{
		pushed = 1;
		ft_pb(length, stack_a, stack_b, 1);
	}
	return (pushed);
}
