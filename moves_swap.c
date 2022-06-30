/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:52:07 by phijano-          #+#    #+#             */
/*   Updated: 2022/06/30 10:08:10 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

static void	ft_swap(int *stack)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	ft_sa(int *stack_a, int show)
{
	ft_swap(stack_a);
	if (show)
		write(1, "sa\n", 3);
}

void	ft_sb(int *stack_b, int show)
{
	ft_swap(stack_b);
	if (show)
		write(1, "sb\n", 3);
}

void	ft_ss(int *stack_a, int *stack_b, int show)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	if (show)
		write(1, "ss\n", 3);
}
