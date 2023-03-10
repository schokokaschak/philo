/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:40:05 by akashets          #+#    #+#             */
/*   Updated: 2023/03/10 16:26:38 by Alexander        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/philo.h"

void	ft_create_threads(t_philo *p)
{
	int			i;
	long int	k;
	pid_t		pid;

	i = -1;
	k = time_now();
	while (++i < p->params->nop)
	{
		pid = fork();
		if (pid == 0)
		{
			p[i].start = k;
			p[i].meal = k;
			p[i].pid = pid;
			routine(&p[i]);
		}
	}
}

void	start_show(t_philo *p)
{
	int	i;
	int	status;

	ft_create_threads(p);
	sem_close(p->params->death);
	sem_unlink("/output");
	sem_close(p->params->fork);
	sem_unlink("/fork");
	i = p->params->nop;
	while (i > 0)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = 0;
			while (i++ < p->params->nop)
				kill(p[i].pid, 9);
			break ;
		}
		i--;
	}
}
