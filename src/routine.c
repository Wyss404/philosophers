/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:02:10 by hdruel            #+#    #+#             */
/*   Updated: 2025/02/11 23:14:10 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_eats(t_philo *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	if (rules->all_ate)
		return ;
	if (rules->nb_philo == 1)
		return ;
	pthread_mutex_lock(&(rules->forks[philo->left_fork_id]));
	action_print(rules, philo->id, "taken a fork");
	pthread_mutex_lock(&(rules->forks[philo->right_fork_id]));
	action_print(rules, philo->id, "taken a fork");
	pthread_mutex_lock(&(rules->meal_check));
	action_print(rules, philo->id, "eating");
	philo->t_last_meal = timestamp();
	pthread_mutex_unlock(&(rules->meal_check));
	if (rules->all_ate)
	{
		pthread_mutex_unlock(&(rules->forks[philo->left_fork_id]));
		pthread_mutex_unlock(&(rules->forks[philo->right_fork_id]));
		return ;
	}
	smart_sleep(rules->time_eat, rules);
	(philo->x_ate)++;
	pthread_mutex_unlock(&(rules->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(rules->forks[philo->right_fork_id]));
}

void	*routine(void *void_philosopher)
{
	int		i;
	t_philo	*philo;
	t_rules	*rules;

	i = 0;
	philo = (t_philo *)void_philosopher;
	rules = philo->rules;
	if (philo->id % 2)
		usleep(7500);
	while (!(rules->dieded) || rules->all_ate)
	{
		philo_eats(philo);
		if (rules->all_ate)
			break ;
		action_print(rules, philo->id, "is sleeping");
		smart_sleep(rules->time_sleep, rules);
		if (rules->all_ate)
			break ;
		action_print(rules, philo->id, "is thinking");
		i++;
	}
	return (NULL);
}

void	exit_launcher(t_rules *rules, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < rules->nb_philo)
		pthread_join(philos[i].thread_id, NULL);
	i = -1;
	while (++i < rules->nb_philo)
		pthread_mutex_destroy(&(rules->forks[i]));
	pthread_mutex_destroy(&(rules->writing));
}

void	death_checker(t_rules *r, t_philo *p)
{
	int	i;

	while (!(r->all_ate))
	{
		i = -1;
		while (++i < r->nb_philo && !(r->dieded))
		{
			pthread_mutex_lock(&(r->meal_check));
			if (time_diff(p[i].t_last_meal, timestamp()) > r->time_die)
			{
				action_print(r, i, "died");
				r->dieded = 1;
			}
			pthread_mutex_unlock(&(r->meal_check));
			usleep(100);
		}
		if (r->dieded)
			break ;
		i = 0;
		while (r->nb_of_eat != -1 && i < r->nb_philo
			&& p[i].x_ate >= r->nb_of_eat)
			i++;
		if (i == r->nb_philo)
			r->all_ate = 1;
	}
}

int	launch_routine(t_rules *rules)
{
	int		i;
	t_philo	*phi;

	i = 0;
	phi = rules->philosophers;
	rules->first_timestamp = timestamp();
	while (i < rules->nb_philo)
	{
		if (pthread_create(&(phi[i].thread_id), NULL, routine, &(phi[i])))
			return (1);
		phi[i].t_last_meal = timestamp();
		i++;
	}
	death_checker(rules, rules->philosophers);
	exit_launcher(rules, phi);
	return (0);
}
