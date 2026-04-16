/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:22:32 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/08 20:14:49 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			a;
	unsigned char	*b;

	b = (unsigned char *)s;
	a = 0;
	while (a < n)
	{
		b[a] = (unsigned char)c;
		a++;
	}
	return (s);
}
/*
int	main(void)
{
	char string[5] = "Hola";
	void *s;
	size_t b;
		
	b = 4;
	s = &string[0];
	printf("%s \n", string);
	ft_memset(s, 'a', b);
	printf("%s", string);
	return (0);	
}*/
