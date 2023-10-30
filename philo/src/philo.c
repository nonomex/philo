/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:56:07 by aammirat          #+#    #+#             */
/*   Updated: 2023/10/30 14:43:32 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	startphilo(t_table *table)
{
	printf ("%d", table->numberoftime);
}

int	main(int argc, char *argv[])
{
	t_table	table;

	if (argc != 5 && argc != 6)
		write (1, "Error\nInvalid number of arguments\n", 35);
	else
	{
		if (initphilo(argc, argv, &table))
			startphilo(&table);
		freephilo(&table);
	}
	return (0);
}
