/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:20:10 by akashets          #+#    #+#             */
/*   Updated: 2023/03/05 15:02:55 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/philo.h"

int	main(int argc, char **argv)
{
	t_params		*params;
	t_philo			*p;

	if (argc < 5 || argc > 6 || !check_input(argv + 1))
	{
		printf("Wrong input!\n");
		printf("Following args are needed or allowed\n");
		printf("number_of_philosophers time_to_die time_to_eat time_to_sleep ");
		printf("[number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	p = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (p == NULL)
		return (1);
	params = init_params(argv);
	ft_init(p, params);
	start_show(p);
	free(p);
	free(params);
	return (0);
}
