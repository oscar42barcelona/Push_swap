#include "push_swap.h"

// Detectar duplicados
int	check_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

// Crea un nodo de memoria y lo empuja a la base del stack A */
int	add_to_stack(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->value = value;
	if (!*stack)
		*stack = new_node;
	else
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new_node;
	}
	return (1);
}

// Libera el Stack
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
