/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:24:39 by phijano-          #+#    #+#             */
/*   Updated: 2022/04/27 15:12:29 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char c)
{
	int				count_words;
	int				word;
	unsigned int	count;

	count_words = 0;
	word = 0;
	count = 0;
	while (str[count])
	{
		if (str[count] != c && word == 0)
		{
			word = 1;
			count_words++;
		}
		else if (str[count] == c)
			word = 0;
		str++;
	}
	return (count_words);
}

static void	ft_free_split(char **split, size_t count_word)
{
	while (count_word)
	{
		free(split[count_word]);
		count_word--;
	}
	free(split[0]);
}

static void	ft_fill_split(char const *s, char c, char **split)
{
	size_t	count;
	size_t	count_word;
	int		start_word;

	count = 0;
	count_word = 0;
	start_word = -1;
	while (count <= ft_strlen(s))
	{
		if (s[count] != c && start_word < 0)
			start_word = count;
		else if ((s[count] == c || count == ft_strlen(s)) && start_word >= 0)
		{
			split[count_word] = ft_substr(s, start_word, count - start_word);
			if (!split[count_word])
			{
				ft_free_split(split, count_word);
				return ;
			}
			count_word++;
			start_word = -1;
		}
		count++;
	}
	split[count_word] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!(s && split))
		return (NULL);
	ft_fill_split(s, c, split);
	if (!split)
		return (NULL);
	return (split);
}
