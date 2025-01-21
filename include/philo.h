/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:35:38 by hdruel            #+#    #+#             */
/*   Updated: 2025/01/21 16:34:32 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stddef.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

struct s_rules;

typedef	struct			s_philo
{
	int					id;
	int					x_ate;
	int					left_fork_id;
	int					right_fork_id;
	long long			t_last_meal;
	struct s_rules		*rules;
	pthread_t			thread_id;
}						t_philo;

typedef struct			s_rules
{
	int					nb_philo;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					nb_of_eat;
	int					dieded;
	int					all_ate;
	long long			first_timestamp;
	pthread_mutex_t		meal_check;
	pthread_mutex_t		forks[250];
	pthread_mutex_t		writing;
	t_philo				philosophers[250];
}						t_rules;

/*   utils   */
void					help_msg(void);
int						ft_atoi(const char *str);
void					clean_exit(t_rules *r, int help);
void					action_print(t_rules *rules, int id, char *string);
long long				timestamp(void);
long long				time_diff(long long past, long long pres);
void					smart_sleep(long long time, t_rules *rules);

/*   init   */
int						init(t_rules *rules, char **argv);

/*   routine   */
int						launch_routine(t_rules *rules);
void					exit_launcher(t_rules *rules, t_philo *philos);

#endif