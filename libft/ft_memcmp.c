/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:31:50 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/15 18:53:16 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			p;

	if (n == 0)
		return (0);
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	p = 0;
	while (p < n)
	{
		if (ss1[p] != ss2[p])
			return (ss1[p] - ss2[p]);
		p++;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%d", ft_memcmp("hola", "holo", 5));
	return (0); 
}*/
