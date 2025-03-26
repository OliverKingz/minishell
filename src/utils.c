/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:27:44 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/26 02:11:55 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	my_perr(const char *msg, bool should_exit, int exit_code)
{
	perror(msg);
	if (should_exit)
		exit(exit_code);
}

void	my_free(void **mem)
{
	if (*mem)
	{
		free(*mem);
		*mem = NULL;
	}
}

void	my_free2d(void ***mem)
{
	int	i;

	if (!mem || !*mem)
		return ;
	i = 0;
	while ((*mem)[i])
	{
		if ((*mem)[i] != NULL)
		{
			free((*mem)[i]);
			(*mem)[i] = NULL;
		}
		i++;
	}
	free(*mem);
	*mem = NULL;
}

void	my_close(int *fd)
{
	if (*fd != -1 && *fd != STDOUT_FILENO && *fd != STDIN_FILENO)
		close(*fd);
	*fd = -1;
}
