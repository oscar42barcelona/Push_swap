/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia4 <jgarcia4@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:56:23 by jgarcia4          #+#    #+#             */
/*   Updated: 2026/04/29 18:15:39 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_format(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atol_safe(char *str, long *result)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	res *= sign;
	if (res > INT_MAX || res < INT_MIN)
		return (0);
	*result = res;
	return (1);
}

void	process_tokens(char **tokens, t_stack **a)
{
	int		j;
	long	number;

	j = 0;
	while (tokens[j])
	{
		if (!is_valid_format(tokens[j]) || !ft_atol_safe(tokens[j], &number))
			error_exit(a, tokens);
		if (check_duplicate(*a, (int)number) || !add_to_stack(a, (int)number))
			error_exit(a, tokens);
		j++;
	}
}
