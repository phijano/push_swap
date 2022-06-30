/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:21:39 by phijano-          #+#    #+#             */
/*   Updated: 2022/04/27 15:16:01 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count_hay;
	size_t	count_nee;

	count_hay = 0;
	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[count_hay] && count_hay < len)
	{
		count_nee = 0;
		while (haystack[count_hay + count_nee] != '\0'
			&& haystack[count_hay + count_nee] == needle[count_nee]
			&& count_hay + count_nee < len)
		{
			if (needle[count_nee + 1] == '\0')
			{
				return ((char *)&haystack[count_hay]);
			}
			count_nee++;
		}
		count_hay++;
	}
	return (NULL);
}
