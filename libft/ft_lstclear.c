/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:37:14 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/19 13:14:56 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}

/*
static void	del_int(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*a;
	t_list	*b;
	int		*x;
	int		*y;

	x = malloc(sizeof(int));
	y = malloc(sizeof(int));
	*x = 1;
	*y = 2;
	a = ft_lstnew(x);
	b = ft_lstnew(y);
	a->next = b;
	ft_lstclear(&a, del_int);
	if (a == NULL)
		printf("list cleared\n");
	return (0);
}
*/

