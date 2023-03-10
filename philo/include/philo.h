/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:21:08 by akashets          #+#    #+#             */
/*   Updated: 2023/03/05 15:03:59 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include	<stdio.h>
# include	<unistd.h>
# include	<pthread.h>
# include	<string.h>
# include	<stdlib.h>
# include	<limits.h>
# include	<sys/time.h>

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
	int				check_tme;
	pthread_mutex_t	*death;
	pthread_mutex_t	*fork;
}			t_params;

typedef struct s_philo
{
	int				id;
	int				iter;
	long int		start;
	long int		meal;
	pthread_t		phils;
	pthread_mutex_t	*forkl;
	pthread_mutex_t	*forkr;
	t_params		*params;
}	t_philo;

int			ft_atoi(const char *str);
int			ft_usleep(long int time);
int			check_death(t_philo *p);
int			check_meals(t_philo *p);
int			check_input(char **av);
long int	time_now(void);
void		*routine(void *ph);
void		end_threads(t_philo *p);
void		ft_create_threads(t_philo *p);
void		start_show(t_philo *p);
void		ft_init(t_philo *p, t_params *params);
void		ft_eat(t_philo *p);
void		ft_print(t_philo *p, int i);
void		check_threads(t_philo *p);
void		ft_error_input(void);
void		free_all(t_philo *p);
t_params	*init_params(char **argv);

#endif
