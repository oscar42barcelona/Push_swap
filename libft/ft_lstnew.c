/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 23:58:12 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/20 00:34:51 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/*
int	main(void)
{
	t_list	*n;
	int		x;

	x = 42;
	n = ft_lstnew(&x);
	printf("content = %d\n", *(int *)n->content);
	if (n->next == NULL)
		printf("next is NULL\n");
	free(n);
	return (0);
}
*/

