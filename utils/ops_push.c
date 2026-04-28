/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia4 <jgarcia4@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:40:18 by jgarcia4          #+#    #+#             */
/*   Updated: 2026/04/28 19:40:27 by jgarcia4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	push_one(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (!src || !*src)
		return (0);
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
	return (1);
}

int	pa(t_stack **a, t_stack **b, t_bench *ops)
{
	if (!push_one(a, b))
		return (0);
	ft_putstr_fd("pa\n", 1);
	if (ops)
	{
		ops->pa++;
		ops->total++;
	}
	return (1);
}

int	pb(t_stack **a, t_stack **b, t_bench *ops)
{
	if (!push_one(b, a))
		return (0);
	ft_putstr_fd("pb\n", 1);
	if (ops)
	{
		ops->pb++;
		ops->total++;
	}
	return (1);
}
