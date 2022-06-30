/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:22:04 by phijano-          #+#    #+#             */
/*   Updated: 2022/06/28 13:17:49 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	unsigned long	num;
	unsigned int	count;
	int				sign;

	sign = 1;
	count = 0;
	num = 0;
	if (str[count] == '+' || str[count] == '-')
		if (str[count++] == '-')
			sign = -1;
	while (str[count] >= '0' && str[count] <= '9')
	{
		num = num * 10 + (str[count] - '0');
		count++;
	}
	if (str[count])
		num = 0;
	if (sign > 0)
		if (num > 2147483647)
			return (0);
	if (sign < 0)
		if (num > 2147483648)
			return (0);
	return ((int)(num * sign));
}
