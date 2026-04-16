/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:05:03 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/16 16:41:57 by osuarez-         ###   ########.fr       */
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


int	val(char *token)
{
	int	i;

	i = 0;
	if ((token[i] == '-' || token[i] == '+') && ft_isdigit(token[i + 1]))
		i++;
	else if (ft_isdigit(token[i]))
		i++;
	else 
		return (1); //0 es error.
	while (ft_isdigit(token[i]))
		i++;
	if (token[i] == '\0')
		return (0); //Bien, esta limpio.
	else
		return (1); //error, hay basura por ahi. 	
}

int ver_val(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (!matrix[i])
			return (1); //token vacio? error!
		if (val(matrix[i]))
			return (1); //esto es error y debe de salir error.
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);/*Si no se especifican parámetros, el programa no deberá mostrar nada y deberá
devolver el control al usuario*/ 
	char	*bm;
	char	**matrix;
	int		i;

	i = 0;
	bm = big_mama(argv);
	matrix = ft_split (bm, ' ');
	if (ver_val(matrix))
	{
		write(2, "Error\n", 6); //stderr
		while (matrix[i])
		{
			printf ("liberando %s\n", matrix[i]);
			free (matrix[i]);
			i++;
		}
		free (matrix);
		return (0);
    }
	while (matrix[i])
	{
		printf ("%s\n", matrix[i]);
		free (matrix[i]);
		i++;
	}
	free (matrix);
	return (0);
}


/*
int	main(int argc, char **argv) esto es para ensenyarle a jon que bola y que me diga porque me falla el valgrind
{
	if (argc < 2)
		return (0);Si no se especifican parámetros, el programa no deberá mostrar nada y deberá
devolver el control al usuario*//* 
	char	*bm;
	char	**matrix;

	bm = big_mama(argv);
	matrix = ft_split (bm, ' '); //splitazo
	int	i;

	i = 0;
	while (matrix[i])
	{
		printf ("%s\n", matrix[i]);
		free (matrix[i]);
		i++;
	}
	free (matrix);
	return (0);
}*/

