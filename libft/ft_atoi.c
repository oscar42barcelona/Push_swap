/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:05:01 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/15 13:06:18 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int	a;
	int	b;
	int	s;

	if (nptr == NULL)
		return (0);
	a = 0;
	s = 1;
	while ((nptr[a] >= 9 && nptr[a] <= 13) || nptr[a] == 32)
		a++;
	if (nptr[a] == '+' || nptr[a] == '-')
	{
		if (nptr[a] == '-')
			s = s * -1;
		a++;
	}
	b = 0;
	while (nptr[a] && ft_isdigit((int)nptr[a]))
	{
		b = b * 10 + (nptr[a] - '0');
		a++;
	}
	return (s * b);
}
/*
int	main(void)
{
	printf("%d",ft_atoi(" "));
	return(0);
}*/
