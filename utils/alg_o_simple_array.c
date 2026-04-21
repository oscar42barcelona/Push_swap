/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_o_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:55:05 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/21 17:12:27 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int my_array[] = {64, 34, 25, 5, 22, 11, 90, 12};
int n = length(my_array);

int	*selection_sort(int *array, int n)
{
	int min_value;
	int	min_index;
	int	i;
	int	j;
	int	k;

	i = 0;
    while (i < n-1) //mientras que i sea menor que el size - 1
	{
        min_index = i;
		j = i + 1;
        while (j < n) //aqui es hasta el mismo size
		{
            if (my_array[j] < my_array[min_index]) //si el valor que esta primero (o arriba): "min_index" es mayor que el valor que esta despues (o abajo): "j" se guarda esta posicion. 
			{
                min_index = j; //se actualiza el mini_index, de esta manera se va guardando el valor menor encontrado. 
            }
			j++; //hasta llegar al final
        }
		min_value = my_array[min_index]; //aqui guardamos el valor mas pequenyo encontrado. 
		k = min_index;//check point del min_index
        while (k > i) 
		{
            my_array[k] = my_array[k-1]; 
			k--;
        }
        my_array[i] = min_value;
		i++;
    }
}

int my_array[] = {64, 34, 25, 5, 22, 11, 90, 12};
int n = length(my_array);

int *selection_sort(int *array, int n)
{
	int	aux;
	int	min_index;
	int	i;
    int	j;

	i = 0;
	while (i < n-1) //mientras que i sea menor que el size - 1
	{
		min_index = i;
		j = i + 1;
		while (j < n) //aqui es hasta el mismo size
		{
			if (my_array[j] < my_array[min_index]) //si el valor que esta primero (o arriba): "min_index" es mayor que el valor que esta despues (o abajo): "j" se guarda esta posicion. 
				min_index = j; //se actualiza el mini_index, de esta manera se va guardando el valor menor encontrado. 
			j++; //hasta llegar al final
		}
		aux = my_array[min_index];
		
		i++;
	}
}

