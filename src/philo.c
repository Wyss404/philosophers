/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:32:22 by hdruel            #+#    #+#             */
/*   Updated: 2025/01/19 00:22:14 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_philo p;

	if (argc < 5)
		help_msg();
	if (init(argc, argv, &p) == 0)
		clean_exit(&p, 1);
	return (0);
}