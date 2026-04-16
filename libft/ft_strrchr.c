/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:44:00 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/13 20:50:24 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*p;
	size_t	size;

	i = 0;
	size = ft_strlen(s);
	while (i <= size)
	{
		if ((unsigned char)s[size - i] == (unsigned char)c)
		{
			p = (char *)&s[size - i];
			return (p);
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    //int   pos;
    const char  cc[] = "Holapeooooooorr";
    char    *p = ft_strrchr(cc, 'o');
    //pos = p - cc;
    printf("%s", p);
    return (0);
}*/
