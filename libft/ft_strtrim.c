/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:24:22 by phijano-          #+#    #+#             */
/*   Updated: 2022/04/26 12:19:39 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getstart(const char *s1, const char *set)
{
	size_t	len;
	size_t	count;

	len = ft_strlen(s1);
	count = 0;
	while (count < len)
	{
		if (ft_strchr(set, s1[count]) == 0)
			return (count);
		count++;
	}
	return (count);
}

static int	ft_getend(const char *s1, const char *set)
{
	size_t	len;
	size_t	count;

	len = ft_strlen(s1);
	count = 0;
	while (count < len)
	{
		if (ft_strchr(set, s1[len - count - 1]) == 0)
			return (len - count);
		count++;
	}
	return (len - count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*newstr;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = ft_getstart(s1, set);
	end = ft_getend(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	newstr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (newstr == NULL)
		return (NULL);
	ft_strlcpy(newstr, s1 + start, end - start + 1);
	return (newstr);
}
