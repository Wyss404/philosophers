/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:35:38 by hdruel            #+#    #+#             */
/*   Updated: 2025/01/19 00:05:33 by hdruel           ###   ########.fr       */
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

typedef struct s_philo
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_of_eat;
	pthread_mutex_t	philosophers;
}					t_philo;

/*   utils   */
void				help_msg(void);
int					ft_atoi(const char *str);
void				clean_exit(t_philo *p, int help);

/*   init   */
int					init(int argc, char **argv, t_philo *p);

/*   routine   */
void				*routine(void *arg);

#endif