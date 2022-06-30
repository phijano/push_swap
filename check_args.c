/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:06:53 by phijano-          #+#    #+#             */
/*   Updated: 2022/06/30 10:04:55 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

static void	ft_free_split(char **array)
{
	int	count;

	count = -1;
	while (array[++count])
		free(array[count]);
	free(array[count]);
	free(array);
}

static int	ft_check_duplicate(int length, int *stack_a)
{
	int	count;
	int	count_dup;
	int	error;

	count = -1;
	error = 0;
	while (count++ < length - 1 && error == 0)
	{
		count_dup = count;
		while (count_dup++ < length - 1 && error == 0)
		{
			if (stack_a[count] == stack_a[count_dup])
				error = 1;
		}
	}
	return (error);
}

static int	ft_check_error(char *str)
{
	int	error;

	error = 0;
	if (ft_strlen(str) > 2)
		error = 1;
	else if (ft_strlen(str) == 2 && ((str[0] != '+' && str[0] != '-')
			|| str[1] != '0'))
		error = 1;
	else if (ft_strlen(str) == 1 && str[0] != '0')
		error = 1;
	return (error);
}

static int	ft_fill_array(int args, char **arg, int *stack_a)
{
	int		count_args;
	int		error;
	char	**array;
	int		count;
	int		count_total;

	count_args = 0;
	error = 0;
	count_total = -1;
	while (++count_args < args && error == 0)
	{
		count = -1;
		array = ft_split(arg[count_args], ' ');
		if (!array)
			return (-1);
		while (++count < ft_count_words(arg[count_args], ' ') && error == 0)
		{
			stack_a[++count_total] = ft_atoi(array[count]);
			if (stack_a[count_total] == 0)
				error = ft_check_error(array[count]);
		}
		ft_free_split(array);
	}
	return (error);
}

int	ft_check_args(int args, char **arg, int *stack_a, int length)
{
	int	error;

	error = ft_fill_array(args, arg, stack_a);
	stack_a[length] = length;
	if (error == 0)
		error = ft_check_duplicate(length, stack_a);
	return (error);
}
