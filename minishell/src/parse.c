/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:26:20 by aammirat          #+#    #+#             */
/*   Updated: 2023/12/13 14:39:51 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	add_histori(char *str, t_linux *shell)
{
	int		i;
	char	**hist;

	shell->nb_history++;
	hist = malloc(sizeof(char *) * (shell->nb_history + 1));
	if (!hist)
		return ;
	i = 0;
	while (i < shell->nb_history - 1)
	{
		hist[i] = put_in(shell->history[i]);
		free(shell->history[i]);
		i++;
	}
	hist[i] = put_in(str);
	hist[i + 1] = 0;
	if (shell->nb_history != 1)
		free(shell->history);
	shell->history = hist;
}

void	parse(char *str, t_linux *shell)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i] && str[i] != ' ')
		j++;
	shell->command = malloc(sizeof(char) * i + 1);
	if (!shell->command)
		return ;
	i = -1;
	while (str[++i] && str[i] != ' ')
		shell->command[i] = str[i];
	shell->command[i] = '\0';
	add_histori(str, shell);
}

void	structing(t_linux *shell)
{
	shell->nb_history = 0;
	shell->end = 0;
}
