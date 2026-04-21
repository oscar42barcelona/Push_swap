/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_o_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:13:18 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/21 18:33:29 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	selection_sort(t_stack *a)
{
	t_stack	min_index;
	t_stack	first;
	t_stack	j;

	penultimo = (*a)->next->next;
	first = *a;
	i = 0;
	while (first->next->next) //mientras sea menor que el size - 1
	{	
		min_index = first;
		j = first->next;
		while (j->next)
		{
			if (j->value < min_index->value)
				min_index = j;//menor valor encontrado
			j = j->next;
		}
		while (min_index->value > first->value)
			sa(a); //asi hago que no sea circular 
			pa(a); //muevo hacia arriba en busqueda de el numero anterior

//tenemos que contar con el null. 
			
			
		first = first->next;
	}
}



//pinga esto es una manera compartoimentada
int	find_smaller(t_stack *i)
{
	t_stack	min_index;
	t_stack	first;
	t_stack	j;
	int		i;

	i = 0;
	while (j->next)
	{
		if (j->value < min_index->value)
			min_index = j;//menor valor encontrado
		j = j->next;
		i++;
	}
	return (i);
}
