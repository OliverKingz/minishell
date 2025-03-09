 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:07:38 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/08 01:18:00 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_input	*init_input(t_shell *mini_sh, char *read_line)
{
	//(void)(read_line);
	if (mini_sh && !mini_sh->input)
	{
		mini_sh->input = (t_input *)ft_calloc(1, sizeof(t_input));
		if (!mini_sh->input)
			free_shell(mini_sh), my_perr("Failed to malloc input", true, errno);
		mini_sh->input->read_line = NULL;
		mini_sh->input->token_lst = NULL;
		mini_sh->input->pid = NULL;
		mini_sh->input->heredocs = NULL;
		mini_sh->input->cmd_count = 0;
		mini_sh->input->hdoc_count = 0;
		mini_sh->input->read_line = ft_strdup(read_line);
		if (!mini_sh->input->read_line)
			free_shell(mini_sh), my_perr("Failed strdup readline", true, errno);
		mini_sh->input->token_lst = init_tokenlist(mini_sh);
		// mini_sh->input->pid = (pid_t *)ft_calloc(mini_sh->input->cmd_count, sizeof(pid_t));
		// if (!mini_sh->input->pid && mini_sh->input->cmd_count != 0)
		// 	return (ft_puterr("pid"), free_input(mini_sh), NULL);
		// mini_sh->input->heredocs = (int *)ft_calloc(mini_sh->input->hdoc_count, sizeof(int));
		// if (!mini_sh->input->heredocs && mini_sh->input->hdoc_count != 0)
		// 	return (ft_puterr("heredocs"), free_input(mini_sh), NULL);
		return (mini_sh->input);
	}
	else
		return (free_shell(mini_sh), exit(EXIT_FAILURE), NULL);
}

void	free_input(t_shell *mini_sh)
{
	if (!mini_sh->input)
		return ;
	if (mini_sh->input->read_line)
		(free(mini_sh->input->read_line), mini_sh->input->read_line = NULL);
	clear_tokenlist(&(mini_sh->input->token_lst));
	if (mini_sh->input->pid)
		(free(mini_sh->input->pid), mini_sh->input->pid = NULL);
	if (mini_sh->input->heredocs)
		(free(mini_sh->input->heredocs), mini_sh->input->heredocs = NULL);
	(free(mini_sh->input), mini_sh->input = NULL);
}
