/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:50:51 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/14 23:06:27 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	init_cmd(t_shell *mini_sh)
{
	t_cmd	cmd;

	cmd.in_fd = STDIN_FILENO;
	cmd.out_fd = STDOUT_FILENO;
	cmd.close_fd = -1;
	cmd.cmd_path = NULL;
	cmd.cmd_args = NULL;
	cmd.env	= envlist_to_str(mini_sh->env);
	return (cmd);
}

void	tokens_to_cmd(t_shell *mini_sh)
{
	t_cmd	cmd;
	t_token	*node;
	char	**args;

	(void)cmd;
	node = mini_sh->input->token_lst;
	args = get_args(node);
	while (*args)
	{
		printf("%s\n", *args);
		args++;
	}
}
