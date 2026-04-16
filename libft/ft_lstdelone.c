/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:42:08 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/19 12:19:46 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*
static void	del_int(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*node;
	int		*x;

	x = malloc(sizeof(int));
	*x = 42;
	node = ft_lstnew(x);
	ft_lstdelone(node, del_int);
	printf("node deleted\n");
	return (0);
}
*/

