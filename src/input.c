/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:07:38 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/16 12:41:37 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_input	*init_input(t_shell *mini_sh, char *read_line)
{
	if (!mini_sh || mini_sh->input)
		return (free_shell(mini_sh), exit(EXIT_FAILURE), NULL);
	mini_sh->input = (t_input *)ft_calloc(1, sizeof(t_input));
	if (!mini_sh->input)
		return (free_shell(mini_sh), my_perr("input", true, errno), NULL);
	mini_sh->input->read_line = expand_vars(read_line, mini_sh);
	if (!mini_sh->input->read_line)
		return (free_shell(mini_sh), my_perr("expanded line", 1, errno), NULL);
	mini_sh->input->token_lst = init_tokenlist(mini_sh);
	if (!mini_sh->input->token_lst)
		return (free_input(&mini_sh), NULL);
	init_input_pid_heredoc(mini_sh);
	return (mini_sh->input);
}

void	init_input_pid_heredoc(t_shell *mini_sh)
{
	t_token	*current;

	mini_sh->input->cmd_count = 0;
	mini_sh->input->hdoc_count = 0;
	current = mini_sh->input->token_lst;
	while (current)
	{
		mini_sh->input->cmd_count += (current->type == COMMAND);
		mini_sh->input->hdoc_count += (current->type == REDIR_HD);
		current = current->next;
	}
	if (mini_sh->input->cmd_count > 0)
	{
		mini_sh->input->pid = (pid_t *)ft_calloc(mini_sh->input->cmd_count,
				sizeof(pid_t));
		if (!mini_sh->input->pid)
			(free_shell(mini_sh), my_perr("input hdoc", 1, errno));
	}
	if (mini_sh->input->hdoc_count > 0)
	{
		mini_sh->input->heredocs = (int *)ft_calloc(mini_sh->input->hdoc_count,
				sizeof(int));
		if (!mini_sh->input->heredocs)
			(free_shell(mini_sh), my_perr("input pid", 1, errno));
	}
}

void	free_input(t_shell **mini_sh)
{
	if (!(*mini_sh)->input)
		return ;
	if ((*mini_sh)->input->read_line)
		my_free((void **)&((*mini_sh)->input->read_line));
	if ((*mini_sh)->input->token_lst)
		clear_tokenlist(&(*mini_sh)->input->token_lst);
	if ((*mini_sh)->input->pid)
		my_free((void **)&((*mini_sh)->input->pid));
	if ((*mini_sh)->input->heredocs)
		my_free((void **)&((*mini_sh)->input->heredocs));
	my_free((void **)&((*mini_sh)->input));
}
