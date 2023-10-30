/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:56:16 by aammirat          #+#    #+#             */
/*   Updated: 2023/10/30 14:42:03 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct timeval	t_time;

typedef struct s_philo {
	int	time_eat;
	int	time_sleep;
	int	time_die;
	int	id;
	int	numberoftime;
}			t_philo;

typedef struct s_table {
	t_philo			*philo;
	pthread_mutex_t	*fork;
	int				nb_philo;
	int				start_time;
	int				time_eat;
	int				time_sleep;
	int				time_die;
	int				numberoftime;
	int				whereinit;
}			t_table;

int		ft_atoi(char *str, char *error);
int		only_int(char *str);
int		ft_putnbr(int c);
int		get_time(void);
int		initphilo(int c, char **str, t_table *table);
void	freephilo(t_table *table);

#endif
