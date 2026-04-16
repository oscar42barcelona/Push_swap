/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:36:21 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/19 14:12:47 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
static void	print_int(void *content)
{
	printf("%d\n", *(int *)content);
}

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
	a->next = b;
	ft_lstiter(a, print_int);
	return (0);
}
*/

