/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:54:42 by osuarez-          #+#    #+#             */
/*   Updated: 2026/02/16 18:51:55 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*p;
	size_t	size;

	i = 0;
	size = ft_strlen(s) + 1;
	while (i < size)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
		{
			p = (char *)&s[i];
			return (p);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	//int	pos;
	const char	cc[] = "Hola";
	char	*p = ft_strchr(cc, 'H');
	//pos = p - cc;
	printf("%s", p);
	return (0);
}*/
