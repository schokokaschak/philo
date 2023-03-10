/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:32:54 by akashets          #+#    #+#             */
/*   Updated: 2023/03/04 16:56:47 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/philo.h"

long int	time_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void	ft_usleep(long int time)
{
	long int	start_time;

	start_time = time_now();
	while (1)
		if ((int)(time_now() - start_time) >= time)
			break ;
}

void	ft_print(t_philo *p, int i)
{
	if (p->params->dead)
		exit (1);
	sem_wait(p->params->death);
	if ((int)(time_now() - p->meal) >= p->params->ttd &&
					!p->params->dead)
	{
		p->params->dead = 1;
		printf("%s%ld %d %s\n", KWHT, p->meal - p->start \
		+ p->params->ttd, p->id, "DIED (ভ_ ভ)");
		exit (1);
	}
	if (i == 1)
		printf("%s%ld %d is eating\n", KBLU, time_now() - p->start, p->id);
	else if (i == 2)
		printf("%s%ld %d is sleeping\n", KMAG, time_now() - p->start, p->id);
	else if (i == 3)
		printf("%s%ld %d is thinking\n", KCYN, time_now() - p->start, p->id);
	else if (i == 4)
		printf("%s%ld %d has taken fork\n", KWHT, time_now() - p->start, p->id);
	sem_post(p->params->death);
}
