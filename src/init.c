/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:45:45 by hdruel            #+#    #+#             */
/*   Updated: 2025/01/19 00:23:50 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_philo(t_philo *p)
{
	pthread_t *threads;
	int verif;
	int i;

	threads = malloc(p->nb_philo * sizeof(pthread_t));
	if (threads == NULL)
        return (0);
	i = -1;
	while(++i < p->nb_philo)
	{
		verif = pthread_create(threads, NULL, routine, NULL);
		if (verif != 0)
		{
			printf("Error creating thread\n");
			free(threads);
			return (0);
		}
	}
	i = -1;
	while(++i < p->nb_philo)
		pthread_join(threads[i], NULL);
	free(threads);
	return (1);
}

int	init(int argc, char **argv, t_philo *p)
{
	p->nb_philo = ft_atoi(argv[1]);
	p->time_die = ft_atoi(argv[2]);
	p->time_eat = ft_atoi(argv[3]);
	p->time_sleep = ft_atoi(argv[4]);
	p->nb_of_eat = 1;
	if (argc == 6)
	{
		p->nb_of_eat = ft_atoi(argv[5]);
		if (p->nb_of_eat == 0)
			p->nb_of_eat = 1;
	}
	if (p->nb_philo < 2 || p->time_die < 1 || p->time_eat < 1)
		return (0);
	if (init_philo(p) == 0)
		clean_exit(p, 0);
	return (1);
}