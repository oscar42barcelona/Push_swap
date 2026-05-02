/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia4 <jgarcia4@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 00:00:00 by jgarcia4          #+#    #+#             */
/*   Updated: 2026/05/02 00:00:00 by jgarcia4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	do_swap(t_stack **s)
{
	t_stack	*a;
	t_stack	*b;

	if (!s || !*s || !(*s)->next)
		return ;
	a = *s;
	b = (*s)->next;
	a->next = b->next;
	b->next = a;
	*s = b;
}

static void	do_push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

static void	do_rotate(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;

	if (!*s || !(*s)->next)
		return ;
	first = *s;
	last = *s;
	while (last->next)
		last = last->next;
	*s = first->next;
	first->next = NULL;
	last->next = first;
}

static void	do_rrotate(t_stack **s)
{
	t_stack	*pen;
	t_stack	*last;

	if (!*s || !(*s)->next)
		return ;
	pen = *s;
	while (pen->next->next)
		pen = pen->next;
	last = pen->next;
	last->next = *s;
	*s = last;
	pen->next = NULL;
}

int	apply_op(char *op, t_stack **a, t_stack **b)
{
	if (op[0] == 's' && op[1] == 'a' && !op[2])
		return (do_swap(a), 1);
	if (op[0] == 's' && op[1] == 'b' && !op[2])
		return (do_swap(b), 1);
	if (op[0] == 's' && op[1] == 's' && !op[2])
		return (do_swap(a), do_swap(b), 1);
	if (op[0] == 'p' && op[1] == 'a' && !op[2])
		return (do_push(a, b), 1);
	if (op[0] == 'p' && op[1] == 'b' && !op[2])
		return (do_push(b, a), 1);
	if (op[0] == 'r' && op[1] == 'a' && !op[2])
		return (do_rotate(a), 1);
	if (op[0] == 'r' && op[1] == 'b' && !op[2])
		return (do_rotate(b), 1);
	if (op[0] == 'r' && op[1] == 'r' && !op[2])
		return (do_rotate(a), do_rotate(b), 1);
	if (op[0] == 'r' && op[1] == 'r' && op[2] == 'a' && !op[3])
		return (do_rrotate(a), 1);
	if (op[0] == 'r' && op[1] == 'r' && op[2] == 'b' && !op[3])
		return (do_rrotate(b), 1);
	if (op[0] == 'r' && op[1] == 'r' && op[2] == 'r' && !op[3])
		return (do_rrotate(a), do_rrotate(b), 1);
	return (0);
}
