/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:51:44 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/19 17:50:12 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include "stdio.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == 0)
		return (0);
	while (a < n && s1[a] && s2[a]
		&& (unsigned char)s1[a] == (unsigned char)s2[a])
		a++;
	if (a == n)
		return (0);
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
/*
int	main(void)
{
	printf("%d", ft_strncmp("hola", "holamundo", 4));
	return (0);
}*/
