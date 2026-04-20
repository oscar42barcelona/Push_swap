/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:51:07 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/20 18:26:28 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
/*
int	compute_disorder(t_stack **a)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;
	int	size;

	mistakes = 0;
	total_pairs = 0;
	size = lsize(a);
	i = 0;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < (size - 1))
		{
			total_pairs += 1;
			if (a->value > a->value):
				mistakes += 1
			j++;
		}
		i++;
	}
	return (mistakes/total_pairs);
}*/

//Ahora traducimos a listas.

int compute_disorder(t_stack **a)
{
    int mistakes;
    int total_pairs;
    t_stack	*first;
	t_stack	*second;

    mistakes = 0;
    total_pairs = 0;
	first = *a;
    while (first->next)
    {
        second = first->next;
        while (second->next)
        {
            total_pairs += 1;
            if (first->value > second->value)
                mistakes += 1;
            second = second->next;
        }
		first = first->next;
    }
    return (mistakes/total_pairs);
}
