/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:50:51 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/15 19:25:56 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	wait_children(t_input *input)
{
	int	status;
	int	i;

	i = 0;
	status = 0;
	while(i < input->cmd_count)
	{
		if (input->pid[i] != -1)
			waitpid(input->pid[i], &status, 0);
		i++;
	}
	return (WEXITSTATUS(status));
}

pid_t	exe_in_child(t_shell *mini_sh, t_token *node, t_cmd *cmd)
{
	pid_t pid;

	(void)mini_sh;
	(void)node;
	pid = fork();
	if (pid != 0)
		return (pid);
	my_close(&(cmd->close_fd));
	dup2(cmd->in_fd, STDIN_FILENO);
	dup2(cmd->out_fd, STDOUT_FILENO);
	if (!cmd->cmd_path && !cmd->cmd_args)
	{
		clear_cmd(cmd);
		free_shell(mini_sh);
		exit(0);
	}
	if (!cmd->cmd_path)
		cmd_not_found(mini_sh, cmd);
	execve(cmd->cmd_path, cmd->cmd_args, cmd->env);
	exit(0);
	return (0);
}

void	execute_cmds(t_shell *mini_sh)
{
	t_cmd	cmd;
	t_token	*node;
	int		pipe1;
	int		pipe2[2];
	int		i;

	pipe1 = -1;
	pipe2[READ_END] = -1;
	pipe2[WRITE_END] = -1;
	node = mini_sh->input->token_lst;
	i = 0;
	while (node)
	{
		cmd = init_cmd(mini_sh, node, &pipe1, pipe2);
		mini_sh->input->pid[i++] = exe_in_child(mini_sh, node, &cmd);
		if (node->type == OP_PIPE)
			node = node->next;
		while (node && node->type != OP_PIPE)
			node = node->next;
		clear_cmd(&cmd);
		my_close(&pipe1);
		my_close(&pipe2[WRITE_END]);
		pipe1 = pipe2[READ_END];
	}
	my_close(&pipe1);
	mini_sh->exit_code = wait_children(mini_sh->input);
}
