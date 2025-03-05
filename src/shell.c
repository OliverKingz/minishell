/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:27:41 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/05 20:51:14 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_input	*init_input(t_input *in_line)
{
	in_line->cmd_count = 0;
	in_line->hdoc_count = 0;
	in_line->last_exit_status = 0;
	in_line = (t_input *)ft_calloc(1, sizeof(t_input));
	in_line->token_lst = (t_token *)ft_calloc(1, sizeof(t_token));
	in_line->pid = (pid_t *)ft_calloc(in_line->cmd_count, sizeof(pid_t));
	in_line->heredocs = (int *)ft_calloc(in_line->hdoc_count, sizeof(int));
	if (!in_line || !in_line->token_lst || !in_line->pid || !in_line->heredocs)
		return (NULL);
	return (in_line);
}

void	free_input(t_input *in_line)
{
	if (!in_line)
		return ;
	if (in_line->token_lst)
		(free(in_line->token_lst), in_line->token_lst = NULL);
	if (in_line->pid)
		(free(in_line->pid), in_line->pid = NULL);
	if (in_line->heredocs)
		(free(in_line->heredocs), in_line->pid = NULL);
	free(in_line);
	in_line->cmd_count = 0;
	in_line->hdoc_count = 0;
	in_line->last_exit_status = 0;
}
