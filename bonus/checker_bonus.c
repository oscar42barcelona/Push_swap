/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia4 <jgarcia4@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 00:00:00 by jgarcia4          #+#    #+#             */
/*   Updated: 2026/05/02 00:00:00 by jgarcia4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static char	*read_line(void)
{
	char	buf[5];
	char	c;
	int		i;
	int		ret;

	i = 0;
	ft_bzero(buf, 5);
	ret = read(0, &c, 1);
	while (ret > 0 && c != '\n')
	{
		if (i >= 4)
		{
			while (ret > 0 && c != '\n')
				ret = read(0, &c, 1);
			return (ft_strdup("?"));
		}
		buf[i++] = c;
		ret = read(0, &c, 1);
	}
	if (ret <= 0 && i == 0)
		return (NULL);
	return (ft_strdup(buf));
}

static int	run_checker(t_stack **a, t_stack **b)
{
	char	*op;

	op = read_line();
	while (op)
	{
		if (!apply_op(op, a, b))
		{
			free(op);
			return (0);
		}
		free(op);
		op = read_line();
	}
	return (1);
}

static void	parse_args(int argc, char **argv, t_stack **a)
{
	char	**tokens;
	int		i;

	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens || !tokens[0])
			error_exit(a, tokens);
		process_tokens(tokens, a);
		free_matrix(tokens);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	parse_args(argc, argv, &a);
	if (!run_checker(&a, &b))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(&a);
		free_stack(&b);
		return (1);
	}
	if (is_sorted(&a) && !b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
