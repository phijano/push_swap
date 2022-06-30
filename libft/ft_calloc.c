/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:22:16 by phijano-          #+#    #+#             */
/*   Updated: 2022/04/27 15:15:07 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	count_zero;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	ptr = malloc (count * size);
	if (!ptr)
		return (NULL);
	count_zero = 0;
	while (count_zero < count * size)
	{
		((char *)ptr)[count_zero] = '\0';
		count_zero++;
	}
	return (ptr);
}
