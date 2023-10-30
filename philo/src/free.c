/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:38:29 by aammirat          #+#    #+#             */
/*   Updated: 2023/10/30 14:39:54 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	freephilo(t_table *table)
{
	int	i;

	i = 0;
	if (table->whereinit >= 1)
		free(table->philo);
	if (table->whereinit >= 2)
	{
		while (i < table->whereinit - 2)
		{
			pthread_mutex_destroy(&table->fork[i]);
			i++;
		}
		free(table->fork);
	}
}
