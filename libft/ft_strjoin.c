/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 10:51:54 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/15 17:32:05 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	a;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1);
	p = malloc(a + ft_strlen(s2) + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		p[a + i] = s2[i];
		i++;
	}
	p[a + i] = '\0';
	return (p);
}
/*
int main(void)
{
    printf("%s", ft_strjoin("Pedro", " buenas"));
    return 0;
}*/
