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
		p[k].phils = 0;
		p[k].meal = 0;
		p[k].forkl = &params->fork[k];
		if (p[k].id == params->nop)
			p[k].forkr = &params->fork[0];
		else
			p[k].forkr = &params->fork[k + 1];
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
	params->death = malloc(sizeof(pthread_mutex_t) * 1);
	if (params->death == NULL)
		return (NULL);
	params->fork = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	if (params->fork == NULL)
		return (NULL);
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
	return (params);
}

void	free_all(t_philo *p)
{
	int	i;

	i = -1;
	while (++i < p->params->nop)
		pthread_mutex_destroy(p[i].forkl);
	pthread_mutex_destroy(p->params->death);
	free(p->params->death);
	free(p->params->fork);
	free(p->params);
	free(p);
}
