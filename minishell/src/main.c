/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:01:32 by aammirat          #+#    #+#             */
/*   Updated: 2023/12/13 16:54:23 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	main(void)
{
	char	*str;
	t_linux	shell;

	structing(&shell);
	while (shell.end == 0)
	{
		str = readline("minishell>>");
		parse(str, &shell);
		if (!is_built(&shell))
			comand(&shell);
		free(str);
		free(shell.command);
	}
	free_all(&shell);
	return (0);
}
