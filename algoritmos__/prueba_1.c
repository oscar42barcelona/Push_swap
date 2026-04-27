/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:27:29 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/27 17:35:33 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
      
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	print_list(t_stack *a)
{
	while (a)
	{
		printf("value: %d | index: %d\n", a->value, a->index);
		a = a->next;
	}
}

int	lst_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

void index_sort(t_stack **a, int size)
{
    t_stack *node;
    t_stack *second;
	t_stack	*copia;
    int     value;
	int		i;

    value = (*a)->value;
    i = 1;
    while (i <= size)
    {
        node = *a;
        while (node)
        {
			second = node->next;
            if (second->value > value && second->value < node->value)
            {
                value = second->value;
                copia = node;
            }
            node = node->next;
        }
        copia->index = i;
        i++;
    }
}


int	main(void)
{
	t_stack	*a;
	t_stack	*n1;
	t_stack	*n2;
	t_stack	*n3;
	t_stack	*n4;
	t_stack	*n5;
	t_stack	*n6;

	n1 = new_node(42);
	n2 = new_node(154);
	n3 = new_node(98);
	n4 = new_node(8);
	n5 = new_node(2);
	n6 = new_node(1);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;

	a = n1;

	printf("Before:\n");
	print_list(a);

	index_sort(&a, lst_size(a));

	printf("\nAfter:\n");
	print_list(a);

	return (0);
}
