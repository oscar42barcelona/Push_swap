/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_medio.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:12:59 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/27 16:28:46 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

static int size(stack **a)
{
	int		size;
	t_stack	**node;

	node = *a;
	size = 0;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

static int rc(int size)
{
	int	i;
	int	b;
	
	i = 0;
	b = 0;
	while (i * i <= size)
	{
		if (i * i == size)
			return (i);
		i++;
	}
	b = i - 1;
	if (i * i - size > size - b * b)
		return (b);
	else
		return (i);
}

void index_sort(t_stack **a, int size)
{
	t_stack	*node;
	t_stack	*copia;
	int		value;

	node = *a;
	value = node->value;
	i = 1;
	while (i <= size)
	{
		node = *a;
		while (node)
		{
			if (value > node->value)
			{
				value = node->value;
				copia = node;
			}
			node->next;
		}
		copia->index = i;
		i++;
	}
}

void  *chunks(int rc, )
{
	int	chunks;
	int	*array;

	chunks = rc(size(a));
	
}
