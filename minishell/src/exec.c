/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:10:31 by aammirat          #+#    #+#             */
/*   Updated: 2023/12/13 15:33:34 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	*coma(char *str)
{
	int		i;
	int		len;
	char	*com;

	len = ft_strlen(str);
	i = 5;
	com = malloc(sizeof(char) * (len + 6));
	if (!com)
		return (NULL);
	com[0] = '/';
	com[1] = 'b';
	com[2] = 'i';
	com[3] = 'n';
	com[4] = '/';
	while (i < len + 5)
	{
		com[i] = str[i - 5];
		i++;
	}
	com[i] = '\0';
	return (com);
}

char	*check_com(char *str)
{
	int		i;
	char	*com;

	i = 0;
	while (str[i])
		i++;
	if (i < 6)
		return (coma(str));
	if (str[0] != '/' || str[1] != 'b' || str[2] != 'i' \
						|| str[3] != 'n' || str[4] != '/')
		return (coma(str));
	else
	{
		com = malloc(sizeof(char) * i + 1);
		if (!com)
			return (NULL);
		i = -1;
		while (str[++i])
			com[i] = str[i];
		com[i] = '\0';
		return (com);
	}
}

void	comand(t_linux *shell)
{
	char	*com;
	char	**args;
	pid_t	pid;
	int		status;

	com = check_com(shell->command);
	if (!com)
		return ;
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		free(com);
		return ;
	}
	if (pid == 0)
	{
		args = ft_split(shell->history[shell->nb_history - 1], ' ');
		if (!args)
			return ;
		execv(com, args);
		perror("execv failed");
		free(com);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, 0);
	free(com);
}
