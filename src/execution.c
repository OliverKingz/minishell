/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:50:51 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/15 12:14:08 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	init_cmd(t_shell *mini_sh, t_token *node)
{
	t_cmd	cmd;

	(void)node;
	cmd.in_fd = STDIN_FILENO;
	cmd.out_fd = STDOUT_FILENO;
	cmd.close_fd = -1;
	cmd.cmd_path = NULL;
	cmd.cmd_args = NULL;
	cmd.env = envlist_to_str(mini_sh->env);
	return (cmd);
}

void	execute_cmds(t_shell *mini_sh)
{
	t_cmd	cmd;
	t_token	*node;
	//int		pipe1[2];

	node = mini_sh->input->token_lst;
	while (node)
	{
		cmd = init_cmd(mini_sh, node);
		if (node->type == OP_PIPE)
		{
			node = node->next;
		}
		//sif (get_token_typr)
		while (node && node->type != OP_PIPE)
			node = node->next;
	}
}
