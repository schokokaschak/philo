/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:41:24 by akashets          #+#    #+#             */
/*   Updated: 2023/03/05 11:12:52 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/philo.h"

int	someone_died(t_philo *p)
{
	ft_print(p, 5);
	p->params->over = 1;
	pthread_mutex_unlock(p->forkl);
	pthread_mutex_unlock(p->forkr);
	return (1);
}

int	check_death(t_philo *p)
{
	long int	now;

	pthread_mutex_lock(p->params->death);
	now = time_now() - p->meal;
	if (now >= p->params->ttd)
	{
		pthread_mutex_unlock(p->params->death);
		return (someone_died(p));
	}
	pthread_mutex_unlock(p->params->death);
	return (0);
}

void	check_threads(t_philo *p)
{
	int	i;

	while (!p->params->ready)
		continue ;
	while (!p->params->over)
	{
		i = -1;
		while (++i < p->params->nop)
			if (check_death(&p[i]) || check_meals(&p[i]))
				p->params->over = 1;
	}
	return ;
}

void	ft_eat(t_philo *p)
{
	pthread_mutex_lock(p->forkl);
	ft_print(p, 4);
	pthread_mutex_lock(p->forkr);
	ft_print(p, 4);
	p->meal = time_now();
	p->iter++;
	ft_usleep(p->params->tte);
	ft_print(p, 1);
	pthread_mutex_unlock(p->forkl);
	pthread_mutex_unlock(p->forkr);
}

void	*routine(void *ph)
{
	t_philo	*p;

	p = (t_philo *)ph;
	while (!p->params->ready)
		continue ;
	if (p->id & 1)
		ft_usleep(p->params->tte * 0.9 + 1);
	while (!p->params->over)
	{
		ft_eat(p);
		ft_usleep(p->params->tts);
		ft_print(p, 2);
		ft_print(p, 3);
	}
	return (NULL);
}
