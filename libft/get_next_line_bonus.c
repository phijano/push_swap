/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:53:00 by phijano-          #+#    #+#             */
/*   Updated: 2022/06/29 13:42:34 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_endl(const char *s)
{
	int	count;

	if (!s)
		return (-1);
	count = 0;
	while (s[count])
	{
		if (s[count] == '\n')
			return (count);
		count++;
	}
	return (-1);
}

static char	*ft_get_buf(int fd, int bytes, char *buf_join)
{
	char	*buf_read;

	buf_read = (char *)malloc(sizeof(*buf_read) * (BUFFER_SIZE) + 1);
	if (!buf_read)
		return (NULL);
	while (bytes > 0 && ft_endl(buf_join) == -1)
	{
		bytes = read(fd, buf_read, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf_read);
			free(buf_join);
			return (NULL);
		}
		if (bytes > 0)
		{
			buf_read[bytes] = '\0';
			buf_join = ft_strjoin(buf_join, buf_read);
		}
	}
	free(buf_read);
	return (buf_join);
}

static char	*ft_get_next_buf(char *buf)
{
	char	*temp;
	int		end;

	end = ft_endl(buf);
	if (end >= 0)
	{
		temp = buf;
		buf = ft_substr(temp, end + 1, ft_strlen(temp) - end + 1);
		free(temp);
		if (buf)
		{
			if (!buf[0])
			{
				free (buf);
				return (NULL);
			}
		}
		return (buf);
	}
	free(buf);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buf_s[4096];
	char		*str;
	int			bytes;
	int			end;

	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = BUFFER_SIZE;
	buf_s[fd] = ft_get_buf(fd, bytes, buf_s[fd]);
	if (!buf_s[fd])
		return (NULL);
	end = ft_endl(buf_s[fd]);
	if (end < 0)
		end = ft_strlen(buf_s[fd]);
	str = ft_substr(buf_s[fd], 0, end + 1);
	buf_s[fd] = ft_get_next_buf(buf_s[fd]);
	return (str);
}
