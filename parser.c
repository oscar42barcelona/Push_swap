#include "push_swap.h"

// O_4: Validar el formato de cada token
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

// O_5 y O_6: Convierte string a long. 
// Comprueba si el algun numero sobrepasa los limites de INT. 
// Devuelve 0 si hay overflow, 1 si el número es válido (O_7).
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
