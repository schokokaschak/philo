/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:41:24 by akashets          #+#    #+#             */
/*   Updated: 2023/03/06 10:59:40 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/philo.h"

void	ft_eat(t_philo *p)
{
	t_params	*par;

	par = p->params;
	sem_wait(par->fork);
	ft_print(p, 4);
	sem_wait(par->fork);
	ft_print(p, 4);
	p->meal = time_now();
	ft_print(p, 1);
	ft_usleep(par->tte);
	p->iter++;
	sem_post(par->fork);
	sem_post(par->fork);
}

void	routine(t_philo *p)
{
	t_params	*par;

	par = p->params;
	while (!par->dead)
	{
		if (par->nop == 1)
		{
			ft_usleep(par->ttd);
			printf("%s%ld %d %s\n", KWHT, p->meal - p->start \
			+ p->params->ttd, p->id, "DIED (ভ_ ভ)");
			exit (1);
		}
		ft_eat(p);
		if (p->iter == par->tme)
			exit (0);
		ft_print(p, 2);
		ft_usleep(par->tts);
		ft_print(p, 3);
	}
	exit (0);
}
