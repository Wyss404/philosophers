/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:26:55 by hdruel            #+#    #+#             */
/*   Updated: 2025/01/19 00:10:45 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	help_msg(void)
{
	printf("\e[0;35m+=====================================================+\n");
	printf("|=====================PHILOSOPHER=====================|\n");
	printf("+=====================================================+\e[0m\n\n");
	printf("\e[0;34m+================================================+\n");
	printf("|\e[0;31m./philo <nb_of_philo> <time_to_die> <time_to_eat>");
	printf(" <time_to_sleep> [nb_of_times_each_philo_must_eat]\e[0m\n");
	printf("\e[0;34m|<number_of_philo> must be greater than \e[0;31m1\e[0m\n");
	printf("\e[0;34m|<time_to_die> must be greater than \e[0;31m0\e[0m\n");
	printf("\e[0;34m|<time_to_eat> must be greater than \e[0;31m0\e[0m\n");
	printf("\e[0;34m|<number_of_times_each_philo_must_eat> (not obligatory)");
	printf("\e[0;34m must be greater than \e[0;31m0\e[0m\n");
	printf("\e[0;34m+================================================+\e[0m\n");
	exit(127);
}

void	clean_exit(t_philo *p, int help)
{
	p->nb_philo = 0;
	p->time_die = 0;
	p->time_eat = 0;
	p->time_sleep = 0;
	p->nb_of_eat = 0;
	if (help == 1)
		help_msg();
}
