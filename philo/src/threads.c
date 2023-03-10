/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:40:05 by akashets          #+#    #+#             */
/*   Updated: 2023/03/05 11:41:21 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/philo.h"

int	check_meals(t_philo *p)
{
	if (p->params->check_tme && p->iter > p->params->tme \
			&& p->id == p->params->nop)
		return (ft_usleep(300));
	return (0);
}

void	end_threads(t_philo *p)
{
	int	i;

	i = -1;
	while (++i < p->params->nop)
		pthread_join(p[i].phils, (void *)&p[i]);
}

void	ft_create_threads(t_philo *p)
{
	int			i;
	long int	k;

	i = -1;
	while (++i < p->params->nop)
		pthread_create(&p[i].phils, NULL, &routine, &p[i]);
	i = -1;
	k = time_now();
	while (++i < p->params->nop)
	{
		p[i].start = k;
		p[i].meal = k;
	}
	p->params->ready = 1;
}

void	start_show(t_philo *p)
{
	int	i;

	i = -1;
	while (++i < p->params->nop)
	{
		if (pthread_mutex_init(p[i].forkl, NULL) == -1)
		{
			printf("Mutex init Fork failed\n");
			return ;
		}
	}
	if (pthread_mutex_init(p->params->death, NULL) == -1)
	{
		printf("Mutex init death failed\n");
		return ;
	}
	ft_create_threads(p);
	check_threads(p);
}
