#include "../includes/philo.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	res;
	int	i;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\v'
		|| nptr[i] == '\n' || nptr[i] == '\f'
		|| nptr[i] == '\r')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

int	ft_isnumb(char *num)
{
	int	i;

	i = 0;
	if (num[i] != '\0')
	{
		while (num[i])
		{
			if (num[i] == '+' || num[i] == '-')
				i++;
			else
				break ;
		}
		while (num[i])
		{
			if (num[i] >= '0' && num[i] <= '9')
				i++;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}