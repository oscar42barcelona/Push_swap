/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:37:22 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/19 17:18:49 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*
static void	*dup_int(void *content)
{
	int	*new;

	new = malloc(sizeof(int));
	if (!new)
		return (NULL);
	*new = *(int *)content * 2;
	return (new);
}

static void	del_int(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*new;
	int		x;
	int		y;

	x = 1;
	y = 2;
	a = ft_lstnew(&x);
	b = ft_lstnew(&y);
	a->next = b;
	new = ft_lstmap(a, dup_int, del_int);
	ft_lstiter(new, del_int);
	ft_lstclear(&new, del_int);
	return (0);
}
*/

