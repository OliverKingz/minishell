/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:53:53 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/06 16:02:44 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_input	*init_input(t_shell *mini_sh, char *read_line)
{
	mini_sh->input->read_line = read_line;
	mini_sh->input->cmd_count = 0;
	mini_sh->input->hdoc_count = 0;
	mini_sh->input->token_lst = (t_token *)ft_calloc(1, sizeof(t_token));
	if (!mini_sh->input->token_lst)
		return (free_input(mini_sh), NULL);
	mini_sh->input->pid = (pid_t *)ft_calloc(mini_sh->input->cmd_count, sizeof(pid_t));
	if (!mini_sh->input->pid)
		return (free_input(mini_sh), NULL);
	mini_sh->input->heredocs = (int *)ft_calloc(mini_sh->input->hdoc_count, sizeof(int));
	if (!mini_sh->input->heredocs)
		return (free_input(mini_sh), NULL);
	return (mini_sh->input);
}

void	free_input(t_shell *mini_sh)
{
	if (!mini_sh->input)
		return ;
	if (mini_sh->input->token_lst)
		(free(mini_sh->input->token_lst), mini_sh->input->token_lst = NULL);
	if (mini_sh->input->pid)
		(free(mini_sh->input->pid), mini_sh->input->pid = NULL);
	if (mini_sh->input->heredocs)
		(free(mini_sh->input->heredocs), mini_sh->input->pid = NULL);
	free(mini_sh->input);
}
