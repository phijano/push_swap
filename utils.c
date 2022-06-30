/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:10:34 by phijano-          #+#    #+#             */
/*   Updated: 2022/06/29 11:06:01 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

int	ft_count_words(const char *str, char c)
{
	int				count_words;
	int				word;
	unsigned int	count;

	count_words = 0;
	word = 0;
	count = -1;
	while (str[++count])
	{
		if (str[count] != c && word == 0)
		{
			word = 1;
			count_words++;
		}
		else if (str[count] == c)
			word = 0;
	}
	if (count == 0)
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	return (count_words);
}

int	ft_count_total_words(int args, char **arg)
{
	int	count;
	int	total_words;

	count = 0;
	total_words = 0;
	while (++count < args)
		total_words = total_words + ft_count_words(arg[count], ' ');
	return (total_words);
}

int	ft_lower(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	ft_big(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_get_index(int length, int *stack_a, int number)
{
	int	count;

	count = -1;
	while (++count < length)
		if (number == stack_a[count])
			break ;
	return (count);
}
