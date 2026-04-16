/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 10:35:05 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/19 18:01:03 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_count(char const *p, char c)
{
	int	a;
	int	count;

	a = 0;
	count = 0;
	while (p[a])
	{
		if (p[a] != c && (a == 0 || p[a - 1] == c))
			count++;
		a++;
	}
	return (count);
}

char	*ft_string(char const *s, char c, int *i)
{
	char	*start;
	int		len;
	int		comienzo;

	while (s[*i] == c)
		(*i)++;
	comienzo = *i;
	start = ft_strchr(&s[*i], c);
	if (!start)
		start = ft_strchr(&s[*i], '\0');
	len = start - &s[*i];
	*i = *i + len;
	return (ft_substr(s, comienzo, len));
}

char	**ft_free(char **array, int used)
{
	int	i;

	i = 0;
	while (i < used)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;	
	int		n_string;
	char	**array;
	int		a;

	if (!s)
		return (NULL);
	i = 0;
	a = 0;
	n_string = ft_count(s, c);
	array = malloc(sizeof(char *) * (n_string + 1));
	if (!array)
		return (NULL);
	while (a < n_string)
	{
		array[a] = ft_string(s, c, &i);
		if (!array[a])
			return (ft_free(array, a));
		a++;
	}
	array[a] = (NULL);
	return (array);
}

int	main(void)
{
	char	**array;
	int		i;

	array = ft_split("HorlarpedrrrorrMundo", 'r');
	i = 0;
	while (array[i])
	{
		printf("%s\n-", array[i]);
		i++;
	}
	return 0;
}
