/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parche_5v_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:19:09 by osuarez-          #+#    #+#             */
/*   Updated: 2026/05/04 15:16:07 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_min_position(t_stack *a)
{
	int		min;
	int		pos;
	int		min_pos;
	t_stack	*current;

	current = a;
	min = current->value;
	pos = 0;
	min_pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

void	rotate_min_forward(t_stack **a, int min_pos, t_bench *ops)
{
	while (min_pos > 0)
	{
		ra(a, ops);
		min_pos--;
	}
}

void	rotate_min_backward(t_stack **a, int min_pos, int size, t_bench *ops)
{
	while (min_pos < size)
	{
		rra(a, ops);
		min_pos++;
	}
}

void	move_min_to_top(t_stack **a, t_bench *ops)
{
	int	min_pos;
	int	size;

	min_pos = get_min_position(*a);
	size = lst_size(a);
	if (min_pos <= size / 2)
		rotate_min_forward(a, min_pos, ops);
	else
		rotate_min_backward(a, min_pos, size, ops);
}

int isqrt(int size)
{
	int i;

	i = 0;
	while (i * i < size)
		i++;
	return (i);
}
