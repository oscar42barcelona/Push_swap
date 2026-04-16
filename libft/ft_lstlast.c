/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 09:53:26 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/19 10:31:04 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
*/

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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
	a->next = b;
	b->next = c;
	printf("%d\n", *(int *)ft_lstlast(a)->content);
	return (0);
}
*/

