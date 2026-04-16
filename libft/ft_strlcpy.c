/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 01:05:35 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/15 19:18:00 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	a;

	a = 0;
	if (size > 0)
	{
		while (a < size - 1 && src[a])
		{
			dst[a] = src[a];
			a++;
		}
		dst[a] = '\0';
	}
	return (ft_strlen(src));
}

/*
int	main(void)
{
	char	dst[] = "pedro";
	char	src[] = "hola";
	size_t		a;

	printf("%s;\n%s;\n", src, dst);
	a = ft_strlcpy(src, dst, 3);
	printf("%s;\n%s;\n%zu", src, dst, a);
	return(0);
}*/
