/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:12:39 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/15 19:07:39 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
//#include <stdio.h>
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tam;
	void	*p;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > INT_MAX / size)
		return (NULL);
	tam = nmemb * size;
	p = malloc(tam);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, tam);
	return (p);
}
/*
int	main(void)
{
	int	*a;
	a = ft_calloc(5, 4);
	printf("%d", a[1]);
	return (0);
}*/
