/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:41:34 by akashets          #+#    #+#             */
/*   Updated: 2023/03/05 09:52:06 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/philo.h"

void	ft_init(t_philo *p, t_params *params)
{
	int	k;

	k = -1;
	while (++k < params->nop)
	{
		p[k].start = 0;
		p[k].id = k + 1;
		p[k].meal = 0;
		p[k].params = params;
		p[k].iter = 0;
	}
}

t_params	*init_params(char **argv)
{
	t_params	*params;

	params = malloc(sizeof(t_params) * 1);
	if (params == NULL)
		return (NULL);
	sem_unlink("/output");
	sem_unlink("/forks");
	params->death = sem_open("/output", O_CREAT, 0660, 1);
	params->fork = sem_open("/forks", O_CREAT, 0660, ft_atoi(argv[1]));
	params->ttd = ft_atoi(argv[2]);
	params->tte = ft_atoi(argv[3]);
	params->check_tme = 0;
	params->tts = ft_atoi(argv[4]);
	if (argv[5] && ft_atoi(argv[5]) > 0)
	{
		params->check_tme = 1;
		params->tme = ft_atoi(argv[5]);
	}
	params->nop = ft_atoi(argv[1]);
	params->ready = 0;
	params->over = 0;
	params->dead = 0;
	return (params);
}
