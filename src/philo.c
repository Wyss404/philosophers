/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:32:22 by hdruel            #+#    #+#             */
/*   Updated: 2025/01/21 16:36:53 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_rules rules;

	if (argc <= 4 || argc >= 7)
		return (help_msg(1));
	if (init(&rules, argv) == 1)
		return (clean_exit(&rules, 1, 1));
	if (launch_routine(&rules) == 1)
		return (clean_exit(&rules, 1, 1));
	return (0);
}
