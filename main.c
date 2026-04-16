/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:05:03 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/16 13:56:10 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

char *big_mama(char **argv)
{
	int		i;
	char	*buffer;
	char	*aux;

	i = 1;
	buffer = argv[i];
	while (argv[i + 1])
	{
		aux = ft_strjoin_m(buffer, argv[i + 1]);
		if (i > 1)
			free (buffer);
		buffer = aux;
		i++;
	}
	return (buffer);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	char	*bm;
	char	**matrix;

	bm = big_mama(argv);
	matrix = ft_split (bm, ' '); //splitazo
	printf ("%s", bm);
	free (bm);
	return (0);
}

/*
int main(int argc, char **argv)
{
	if (argc <= 1)
		return (0); //0_1
	int		i;
	char	**matrix;
	
	i = 1;
}*/
