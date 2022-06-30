/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:04:12 by phijano-          #+#    #+#             */
/*   Updated: 2022/06/30 10:08:35 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

static int	ft_do_move_more(int *stack_a, int *stack_b, int length, char *str)
{
	int	error;

	error = 0;
	if (ft_strncmp(str, "ra\n", 3) == 0)
		ft_ra(length, stack_a, 0);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		ft_rb(length, stack_b, 0);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		ft_rr(length, stack_a, stack_b, 0);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		ft_rra(length, stack_a, 0);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		ft_rrb(length, stack_b, 0);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		ft_rrr(length, stack_a, stack_b, 0);
	else
		error = 1;
	return (error);
}

static int	ft_do_move(int *stack_a, int *stack_b, int length, char *str)
{
	int	error;

	error = 0;
	if (ft_strncmp(str, "sa\n", 3) == 0)
		ft_sa(stack_a, 0);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		ft_sb(stack_b, 0);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ft_ss(stack_a, stack_b, 0);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		ft_pa(length, stack_a, stack_b, 0);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		ft_pb(length, stack_a, stack_b, 0);
	else
		error = ft_do_move_more(stack_a, stack_b, length, str);
	return (error);
}

static int	ft_check_sort(int *stack_a, int *stack_b, int length)
{
	char	*str;
	int		error;

	error = 0;
	str = get_next_line(0);
	if (str)
		error = ft_do_move(stack_a, stack_b, length, str);
	while (str && !error)
	{
		str = get_next_line(0);
		if (str)
			error = ft_do_move(stack_a, stack_b, length, str);
	}
	if (!error)
	{
		if (length != stack_a[length])
			error = 1;
		else
			if (ft_is_sorted(length, stack_a) == 0)
				error = 1;
	}
	return (error);
}

static void	ft_checker(int *stack_a, int length)
{
	int	error;
	int	*stack_b;

	stack_b = (int *)malloc(sizeof(*stack_b) * (length + 1));
	if (!stack_b)
	{
		free(stack_a);
		exit(-1);
	}
	stack_a[length] = length;
	stack_b[length] = 0;
	error = ft_check_sort(stack_a, stack_b, length);
	if (error == 1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(stack_b);
}

int	main(int args, char **arg)
{
	int	*stack_a;
	int	total_numbers;
	int	error;

	if (args > 1)
	{
		total_numbers = ft_count_total_words(args, arg);
		stack_a = (int *)malloc(sizeof(*stack_a) * (total_numbers + 1));
		if (!stack_a)
			return (-1);
		error = ft_check_args(args, arg, stack_a, total_numbers);
		if (error == 1)
			write(2, "Error\n", 6);
		else
			ft_checker(stack_a, total_numbers);
		free(stack_a);
	}
	return (0);
}
