/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:43:35 by phijano-          #+#    #+#             */
/*   Updated: 2022/06/30 10:01:34 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

int	main(int args, char **arg)
{
	int	error;
	int	*stack_a;
	int	total_numbers;

	if (args > 1)
	{
		total_numbers = ft_count_total_words(args, arg);
		stack_a = (int *)malloc(sizeof(*stack_a) * (total_numbers + 1));
		if (!stack_a)
			return (0);
		error = ft_check_args(args, arg, stack_a, total_numbers);
		if (error == 1)
			write(2, "Error\n", 6);
		else
		{
			stack_a = ft_convert_index(total_numbers, stack_a);
			ft_sort(total_numbers, stack_a);
		}
		free(stack_a);
	}
	return (0);
}
