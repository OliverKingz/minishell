/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:27:44 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/08 18:23:23 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	my_perr(const char *msg, bool should_exit, int exit_status)
{
	perror(msg);
	if (should_exit)
		exit(exit_status);
}

void	my_free(void **mem)
{
	if (*mem)
	{
		free(*mem);
		*mem = NULL;
	}	
}

int	my_strchr_pos(const char *s, char c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
