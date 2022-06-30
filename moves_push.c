/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:53:56 by phijano-          #+#    #+#             */
/*   Updated: 2022/06/30 10:07:35 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

static void	ft_make_room_push(int length, int *stack)
{
	int	count;

	count = stack[length];
	while (count-- > 0)
		stack[count + 1] = stack[count];
}

static void	ft_arrange_after_push(int length, int *stack)
{
	int	count;

	count = 0;
	while (++count <= stack[length])
		stack[count - 1] = stack[count];
}

static void	ft_push(int length, int *stack_pusher, int *stack_pushed)
{
	ft_make_room_push(length, stack_pushed);
	stack_pushed[0] = stack_pusher[0];
	stack_pushed[length] = stack_pushed[length] + 1;
	stack_pusher[length] = stack_pusher[length] - 1;
	ft_arrange_after_push(length, stack_pusher);
}

void	ft_pa(int length, int *stack_a, int *stack_b, int show)
{
	ft_push(length, stack_b, stack_a);
	if (show)
		write(1, "pa\n", 3);
}

void	ft_pb(int length, int *stack_a, int *stack_b, int show)
{
	ft_push(length, stack_a, stack_b);
	if (show)
		write(1, "pb\n", 3);
}
