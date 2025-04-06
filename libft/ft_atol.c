#include "libft.h"

long	ft_atol(const char *str)
{
	unsigned int	i;
	long int		nb;
	long			sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (sign * nb);
}
