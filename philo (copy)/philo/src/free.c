/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:38:29 by aammirat          #+#    #+#             */
/*   Updated: 2023/11/07 17:21:38 by aammirat         ###   ########lyon.fr   */
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
		free (table->islock);
		while (i < table->whereinit - 12)
		{
			pthread_mutex_destroy(&table->fork[i]);
			i++;
		}
		free(table->fork);
	}
	if (table->whereinit >= 10)
		free(table->tred);
	//free(table->islock);
}
//table->writ
//table->isded
//table->philo[i].number
//table->tred 
//table->fork[i]
//table->islock 
	
