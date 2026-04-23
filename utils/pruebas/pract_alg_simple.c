/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pract_alg_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:13:18 by osuarez-          #+#    #+#             */
/*   Updated: 2026/04/23 16:45:50 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../push_swap.h"

typedef struct s_stack
{
    int             value;
    struct s_stack  *next;
}   t_stack;

void	sa(t_stack **a);
int		pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
int		pb(t_stack **a, t_stack **b);
void    rrb(t_stack **b);

void	selection_sort(t_stack **a, t_stack **b)
{
	t_stack *min_index;
	t_stack *j;

	while ((*a)->next) //mientras sea menor que el size - 1
	{
		min_index = *a;;
		j = (*a)->next;
		while (j)
		{
			if (j->value < min_index->value)
				min_index = j; //menor valor encontrado
			j = j->next;
		}
		while (*a != min_index)
			ra(a); //muevo hacia arriba en busqueda de el numero anterior
		pb(a, b);
	}
	while (pa(a, b));
}

#include <stdio.h>
#include <stdlib.h>


void    print_list(t_stack *a)
{
    int i = 1;

    while (a)
    {
        printf("index %d -> value: %d\n", i, a->value);
        a = a->next;
        i++;
    }
}

t_stack *new_node(int value)
{
    t_stack *node = malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->value = value;
    node->next = NULL;
    return (node);
}

int main(void)
{
    t_stack *a;
	t_stack	*b;
    t_stack *n1;
    t_stack *n2;
    t_stack *n3;
    t_stack *n4;
    t_stack *n5;
    t_stack *n6;

    n1 = new_node(42);
    n2 = new_node(1);
    n3 = new_node(79);
    n4 = new_node(8);
    n5 = new_node(176);
    n6 = new_node(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    a = n1;
	
	b = NULL;

    print_list(a);
	selection_sort(&a, &b);	
	print_list(a);

    free(n6);
    free(n5);
    free(n4);
    free(n3);
    free(n2);
    free(n1);

    return (0);
}
