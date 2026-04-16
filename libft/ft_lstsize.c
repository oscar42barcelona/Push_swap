/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 09:12:38 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/19 09:49:07 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
*/

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
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
	printf("%d\n", ft_lstsize(a));
	return (0);
}
*/

