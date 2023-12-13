/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isbuilt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:16:48 by aammirat          #+#    #+#             */
/*   Updated: 2023/12/13 15:30:04 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	is_same(char *str, char *cmp)
{
	int	i;

	i = 0;
	while (str[i] && cmp[i])
	{
		if (str[i] != cmp[i])
			return (0);
		i++;
	}
	if (cmp[i] != '\0')
		return (0);
	return (1);
}

int	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && (str[i] < 9 || str[i] > 13))
			return (0);
		i++;
	}
	return (1);
}

int	is_built(t_linux *shell)
{
	if (is_same(shell->command, "cd"))
		ft_cd(shell->history[shell->nb_history - 1]);
	else if (is_same(shell->command, "pwd"))
		ft_pwd();
	else if (is_same(shell->command, "exit"))
		ft_exit(shell);
	else if (is_empty(shell->command))
		return (1);
	else
		return (0);
	return (1);
}
