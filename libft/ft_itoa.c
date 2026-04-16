/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia4 <jgarcia4@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 23:20:49 by jgarcia4          #+#    #+#             */
/*   Updated: 2026/04/08 23:20:52 by jgarcia4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(long num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len = 1;
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static void	fill_str(char *str, long num, int len)
{
	str[len] = '\0';
	if (num == 0)
	{
		str[0] = '0';
		return ;
	}
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		len--;
		str[len] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	num = n;
	len = count_len(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	fill_str(str, num, len);
	return (str);
}
