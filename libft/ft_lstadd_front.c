/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 01:10:27 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/20 01:46:03 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
int	main(void)
{
	t_list	*a;
	t_list	*b;
	int		x;
	int		y;

	x = 1;
	y = 2;
	a = ft_lstnew(&x);
	b = ft_lstnew(&y);
	ft_lstadd_front(&a, b);
	printf("%d\n", *(int *)a->content);
	printf("%d\n", *(int *)a->next->content);
	return (0);
}
*/

