/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 10:48:27 by osuarez-          #+#    #+#             */
/*   Updated: 2026/02/16 19:19:01 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	p = malloc(len + 1);
	if (!p)
		return (NULL);
	i = 0;
	if (ft_strlen(s) > start)
	{
		while (i < len && s[start + i])
		{
			p[i] = s[start + i];
			i++;
		}
	}
	p[i] = '\0';
	return (p);
}
/*
int main(void)
{
    printf("%s", ft_substr("holapedro", 1, 5));
    return 0;
}*/
