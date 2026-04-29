/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia4 <jgarcia4@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 00:00:00 by jgarcia4          #+#    #+#             */
/*   Updated: 2026/04/29 18:15:50 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack **stack, char **matrix)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(stack);
	free_matrix(matrix);
	exit(1);
}
