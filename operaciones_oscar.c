/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operaciones_oscar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:26:04 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/17 17:20:31 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
void	sa(t_stack **a)
{
	
	t_stack	*first;
	t_stack	*second;
	

	if (!a)
		return;
	if (ft_lstsize(*a) < 2)
		return;
	first = *a;
	second = (*a)->next;

	first = (*a)->next->next;
	second->next = first;
	*a = second;
}
