/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia4 <jgarcia4@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 23:34:19 by jgarcia4          #+#    #+#             */
/*   Updated: 2026/04/08 23:34:20 by jgarcia4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	s1_len;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(""));
	start = 0;
	s1_len = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	end = s1_len - 1;
	while (ft_strchr(set, s1[end]) && end >= start)
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
