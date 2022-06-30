/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:22:43 by phijano-          #+#    #+#             */
/*   Updated: 2022/04/26 12:50:47 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*pnt_str;
	int		count;

	count = 0;
	while (s1[count])
		count++;
	pnt_str = (char *)malloc(sizeof (*pnt_str) * (count + 1));
	if (!pnt_str)
		return (NULL);
	count = 0;
	while (s1[count])
	{
		pnt_str[count] = s1[count];
		count++;
	}
	pnt_str[count] = '\0';
	return (pnt_str);
}
