/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:50:03 by aammirat          #+#    #+#             */
/*   Updated: 2023/12/13 16:53:48 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void    free_all(t_linux *shell)
{
    int i;

    i = 0;
    while (i < shell->nb_history)
    {
        free(shell->history[i]);
        i++;
    }
    free(shell->history);
}
