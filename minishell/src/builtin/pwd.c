/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:02:04 by aammirat          #+#    #+#             */
/*   Updated: 2023/12/13 14:23:28 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	ft_pwd(void)
{
	char	*temp;

	temp = getcwd(NULL,0);
	if (temp)
	{
		printf ("%s\n", temp);
		free(temp);
	}
	else 
		printf ("where am i\n");
}