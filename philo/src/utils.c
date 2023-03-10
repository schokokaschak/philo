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

int	ft_usleep(long int time)
{
	long int	start_time;

	start_time = time_now();
	while ((time_now() - start_time) < time)
		usleep(150);
	return (1);
}

void	ft_print(t_philo *p, int i)
{
	pthread_mutex_lock(p->params->death);
	if (p->params->over)
	{
		pthread_mutex_unlock(p->params->death);
		return ;
	}
	if (i == 1)
		printf("%s%ld %d is eating\n", KBLU, time_now() - p->start, p->id);
	else if (i == 2)
		printf("%s%ld %d is sleeping\n", KMAG, time_now() - p->start, p->id);
	else if (i == 3)
		printf("%s%ld %d is thinking\n", KCYN, time_now() - p->start, p->id);
	else if (i == 4)
		printf("%s%ld %d has taken fork\n", KWHT, time_now() - p->start, p->id);
	else if (i == 5)
		printf("%s%ld %d DIED (ভ_ ভ)\n", KWHT, time_now() - p->start, p->id);
	pthread_mutex_unlock(p->params->death);
}

void	ft_error_input(void)
{
	printf("Wrong input!\n");
	printf("Following args are needed or allowed\n");
	printf("number_of_philosophers time_to_die time_to_eat time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\n");
}
