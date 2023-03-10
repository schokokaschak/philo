/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:21:08 by akashets          #+#    #+#             */
/*   Updated: 2023/03/06 10:55:53 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>

# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

typedef struct s_params
{
	int				ready;
	int				tte;
	int				ttd;
	int				tts;
	int				tme;
	int				over;
	int				nop;
	int				dead;
	int				check_tme;
	sem_t			*death;
	sem_t			*fork;
}			t_params;

typedef struct s_philo
{
	int				id;
	int				iter;
	long int		start;
	long int		meal;
	int				pid;
	t_params		*params;
}	t_philo;

int			ft_atoi(const char *str);
void		ft_usleep(long int time);
int			check_death(t_philo *p);
int			check_meals(t_philo *p);
int			check_input(char **av);
long int	time_now(void);
void		routine(t_philo *p);
void		end_threads(t_philo *p);
void		ft_create_threads(t_philo *p);
void		start_show(t_philo *p);
void		ft_init(t_philo *p, t_params *params);
void		ft_eat(t_philo *p);
void		ft_print(t_philo *p, int i);
void		*check_threads(void *ph);
t_params	*init_params(char **argv);

#endif
