/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuarez- <osuarez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:26:20 by osuarez-          #+#    #+#             */
/*   Updated: 2026/01/19 17:26:28 by osuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_count(int n)
{
    int c;
    
    c = 0;
    while (n > 0)
    {
        n = n / 10;
        c++;
    }
    return (c);
}


char    *ft_itoa(int n)
{
    char    *string;
    int     i;
    int     c;
    int     s;

    s = 0;
    if (n < 0)
    {
        s = 1;
        n = n * -1;
    }    
    c = ft_count(n);
    string = malloc((c + 1 + s) * sizeof(char));
    if (s == 1)
    {
        string[0] = '-';
        
    }
    i = c - 1 + s;
    while (i)
    {
        string[i] = (n % 10) + '0';
        n = n / 10;
        i--;
    }
    string[i + s] = n + '0';
    string[c + 1] = '\0';
    return (string);
}

int main(void)
{
    printf("%s", ft_itoa(-1998989));
    return (0);
}


