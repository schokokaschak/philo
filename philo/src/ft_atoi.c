/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@student.42wolfsbur      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:57:32 by akashets          #+#    #+#             */
/*   Updated: 2023/02/28 10:36:23 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/philo.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	long	i;
	int		k;

	k = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\f' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
	{
		k = -1;
		str++;
	}		
	else if (*str == '+')
		str++;
	i = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{	
		if (i == 0)
			i = *str - 48;
		else
			i = (i * 10) + (*str - 48);
		str++;
	}
	return (i * k);
}

int	check_input(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!arg_is_number(av[i]))
			return (0);
		i++;
	}
	if (ft_atoi(av[0]) <= 0 || ft_atoi(av[1]) <= 0 || \
	ft_atoi(av[2]) <= 0 || ft_atoi(av[3]) <= 0)
		return (0);
	return (1);
}
