/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:26:55 by hdruel            #+#    #+#             */
/*   Updated: 2025/02/07 03:38:22 by hdruel           ###   ########.fr       */
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

int	help_msg(int error)
{
	printf("\e[0;32m+=================================================+\n");
	printf("|                                                 |\n");
	printf("|                   PHILOSOPHER                   |\n");
	printf("|                                                 |\n");
	printf("+=================================================+\e[0m\n\n");
	printf("\e[0;34m+=================================================+\n");
	printf("|\e[0;32mUsage : ");
	printf("./philo <nb_of_philo> <time_to_die> <time_to_eat>");
	printf(" <time_to_sleep> [nb_of_times_each_philo_must_eat]\e[0m\n");
	printf("\e[0;34m|<number_of_philo> must be greater than \e[0;31m1\e[0m");
	printf("\e[0;34m and less than \e[0;31m251\e[0m\n");
	printf("\e[0;34m|<time_to_die> must be greater than \e[0;31m0\e[0m");
	printf("\e[0;34m and less than \e[0;31m2147483648\e[0m\n");
	printf("\e[0;34m|<time_to_die> must be greater than \e[0;31m0\e[0m");
	printf("\e[0;34m and less than \e[0;31m2147483648\e[0m\n");
	printf("\e[0;34m|<time_to_sleep> must be greater than \e[0;31m0\e[0m");
	printf("\e[0;34m and less than \e[0;31m2147483648\e[0m\n");
	printf("\e[0;34m|[number_of_times_each_philo_must_eat](not obligatory)");
	printf("\e[0;34m must be greater than \e[0;31m0\e[0m");
	printf("\e[0;34m and less than \e[0;31m2147483648\e[0m\n");
	printf("\e[0;34m+=================================================+\e[0m\n");
	return (error);
}

int	clean_exit(t_rules *r, int error)
{
	r->nb_philo = 0;
	r->time_die = 0;
	r->time_eat = 0;
	r->time_sleep = 0;
	r->nb_of_eat = 0;
	return (help_msg(error));
}
