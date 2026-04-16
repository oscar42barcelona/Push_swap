/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:47:19 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/19 11:24:58 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

/*
int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
	int		x;
	int		y;
	int		z;

	x = 1;
	y = 2;
	z = 3;
	a = ft_lstnew(&x);
	b = ft_lstnew(&y);
	c = ft_lstnew(&z);
	ft_lstadd_back(&a, b);
	ft_lstadd_back(&a, c);
	printf("%d\n", *(int *)ft_lstlast(a)->content);
	return (0);
}
*/

