/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:15:55 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/17 14:15:55 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	a;
	size_t	b;
	size_t	c;

	if (!big || !little)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	a = 0;
	c = ft_strlen(little);
	while (a < len && big[a] && len - a >= c)
	{
		b = 0;
		while (a + b < len && big[a + b] == little[b])
		{
			if (little[b + 1] == '\0')
				return ((char *)&big[a]);
			b++;
		}
		a++;
	}
	return (NULL);
}

/*
int	main(void)
{
	printf("%s", ft_strnstr("holamundo", "am", 10));
	return (0);
}*/
