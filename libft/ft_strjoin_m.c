/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_m.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:32:49 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/15 17:54:00 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_m(char const *s1, char const *s2)
{
	char    *p;
	size_t  a;
	size_t  i;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1);
	p = malloc(a + ft_strlen(s2) + 2); //**:)
	if (!p)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = ' '; //:)
	i = 1;
	while (s2[i - 1])  //:)
	{
		p[a + i] = s2[i - 1]; //:)
		i++;
	}
	p[a + i] = '\0';
	return (p);
}
