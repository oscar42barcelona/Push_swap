/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 13:33:17 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/19 18:22:44 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_posicion(char const *s1, char const *set, int signo)
{
	int	a;
	int	b;

	b = 0;
	if (signo == -1)
		b = ft_strlen(s1) - 1;
	while (b >= 0 && s1[b])
	{
		a = 0;
		while (set[a] && set[a] != s1[b])
		{
			if (set[a + 1] == '\0' && signo == -1)
				return (b + 1);
			if (set[a + 1] == '\0')
				return (b);
			a++;
		}
		b = b + (1 * signo);
	}
	return (ft_strlen(s1));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		pi;
	int		pf;
	char	*p;

	pi = ft_posicion(s1, set, 1);
	pf = ft_posicion(s1, set, -1);
	if (pi >= pf)
		return (ft_substr(s1, 0, 0));
	len = pf - pi;
	p = ft_substr (s1, pi, len);
	return (p);
}
/*
int	main(void)
{
	printf("%s-", ft_strtrim("++--+++hola","+-"));	
	return 0;	
}*/
