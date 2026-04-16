/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:31:48 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/19 17:56:48 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*p;

	if (!s)
		return (NULL);
	p = malloc(ft_strlen(s) + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*
int	main(void)
{
	printf("%s", ft_strdup("Hola"));
	return 0;
}*/
