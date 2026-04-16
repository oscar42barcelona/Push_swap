/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:40:24 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/15 17:00:14 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			p;
	unsigned char	*ss;	

	if (n == 0)
		return (NULL);
	p = 0;
	ss = (unsigned char *)s;
	while (p < n)
	{
		if (ss[p] == (unsigned char)c)
			return (&ss[p]);
		p++;
	}
	return (NULL);
}
/*
int	main(void)
{
	unsigned char   *ss = ft_memchr("peddrolo", 'd', 0);
	printf("%s", ss);
	return (0);
}*/
