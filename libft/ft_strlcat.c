/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:44:47 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/19 18:02:44 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	cap;
	size_t	i;
	size_t	d;
	size_t	s;

	s = ft_strlen(src);
	if (dstsize == 0)
		return (s);
	d = ft_strlen(dst);
	if (d >= dstsize)
		return (dstsize + s);
	i = 0;
	cap = (dstsize - 1) - d;
	while (src[i] && i < cap)
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (d + s);
}
