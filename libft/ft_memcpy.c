/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:28:25 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/08 20:59:50 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include "stdio.h"
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			a;
	unsigned char	*d;
	unsigned char	*s;

	a = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	while (a < n)
	{
		d[a] = s[a];
		a++;
	}
	return (dest);
}
/*
int	main(void)
{
	size_t a = 4;
	char *src = "Hola";
	char dest[5] = "p";
	void *d = dest;
	void *s = src;

	ft_memcpy(d, s, a);
	printf("%s\n %s", src, dest);
	return (0);
}*/
