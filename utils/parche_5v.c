/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parche_5v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:08:58 by osuarez-          #+#    #+#             */
/*   Updated: 2026/05/04 15:15:58 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack **a, t_bench *ops)
{
	if ((*a)->value > (*a)->next->value)
		sa(a, ops);
}

void	sort_three(t_stack **a, t_bench *ops)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, ops);
	else if (first > second && second > third)
	{
		sa(a, ops);
		rra(a, ops);
	}
	else if (first > second && second < third && first > third)
		ra(a, ops);
	else if (first < second && second > third && first < third)
	{
		sa(a, ops);
		ra(a, ops);
	}
	else if (first < second && second > third && first > third)
		rra(a, ops);
}

void	sort_four(t_stack **a, t_stack **b, t_bench *ops)
{
	move_min_to_top(a, ops);
	pb(a, b, ops);
	sort_three(a, ops);
	pa(a, b, ops);
}

void	sort_five(t_stack **a, t_stack **b, t_bench *ops)
{
	move_min_to_top(a, ops);
	pb(a, b, ops);
	move_min_to_top(a, ops);
	pb(a, b, ops);
	sort_three(a, ops);
	pa(a, b, ops);
	pa(a, b, ops);
}

void	sort_small(t_stack **a, t_stack **b, t_bench *ops)
{
	int	size;

	size = lst_size(a);
	if (size == 2)
		sort_two(a, ops);
	else if (size == 3)
		sort_three(a, ops);
	else if (size == 4)
		sort_four(a, b, ops);
	else if (size == 5)
		sort_five(a, b, ops);
}
