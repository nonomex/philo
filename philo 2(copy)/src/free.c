/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:38:29 by aammirat          #+#    #+#             */
/*   Updated: 2023/11/09 13:58:31 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	destroymutex(t_table *table)
{
	int	i;

	if (table->whereinit - table->nb_philo >= 8)
	{
		i = -1;
		while (++i < table->nb_philo && \
		(table->whereinit - table->nb_philo) - 8 - i > 0)
			pthread_mutex_destroy(&table->philo[i].number);
	}
	if (table->whereinit - (table->nb_philo * 2) >= 9)
	{
		i = -1;
		while (++i < table->nb_philo && \
		(table->whereinit - table->nb_philo * 2) - 8 - i > 0)
			pthread_mutex_destroy(&table->philo[i].number);
	}
	if (table->whereinit - table->nb_philo >= 6)
		free(table->philo);
}

void	freephilo(t_table *table)
{
	int	i;

	i = -1;
	if (table->whereinit >= 3)
	{
		while (++i < table->nb_philo && (table->whereinit - 3) - i > 0)
			pthread_mutex_destroy(&table->fork[i]);
	}
	if (table->whereinit >= 1)
		free(table->fork);
	if (table->whereinit >= 2)
		free(table->islock);
	if (table->whereinit - table->nb_philo >= 3)
		pthread_mutex_destroy(&table->writ);
	if (table->whereinit - table->nb_philo >= 4)
		pthread_mutex_destroy(&table->isded);
	if (table->whereinit - table->nb_philo >= 5)
		free(table->tred);
	destroymutex(table);
}
