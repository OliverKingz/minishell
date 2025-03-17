/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:50:51 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/17 14:54:00 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	wait_children(t_input *input)
{
	int	status;
	int	i;

	i = 0;
	status = 0;
	while (i < input->pipe_count + 1)
	{
		if (input->pid[i] != -1)
			waitpid(input->pid[i], &status, 0);
		i++;
	}
	return (WEXITSTATUS(status));
}

// void	man_redirections(t_shell *mini_sh, t_token *node, t_cmd *cmd)
// {
// 	while (node)
// 	{
// 		if (node_)
// 		node = node->next;
// 	}
// }

pid_t	exe_in_child(t_shell *mini_sh, t_token *node, t_cmd *cmd)
{
	pid_t	pid;
	t_token	*cmd_node;
	int		bi;

	pid = fork();
	if (pid != 0)
		return (pid);
	my_close(&(cmd->close_fd));
	dup2(cmd->in_fd, STDIN_FILENO);
	dup2(cmd->out_fd, STDOUT_FILENO);
	(my_close(&(cmd->in_fd)), my_close(&(cmd->out_fd)));
	cmd_node = get_token_type(node, COMMAND);
	if (!cmd_node)
		(clear_cmd(cmd), free_shell(mini_sh), exit(0));
	if (!cmd->cmd_path)
		cmd_not_found(mini_sh, cmd);
	bi = check_if_bi(cmd_node);
	if (bi)
		bi = exec_bi(mini_sh, cmd_node, bi);
	else
		execve(cmd->cmd_path, cmd->cmd_args, cmd->env);
	(my_close(&(cmd->in_fd)), my_close(&(cmd->out_fd)));
	(clear_cmd(cmd), free_shell(mini_sh), exit(bi));
	return (bi);
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
		if (node->type == OP_PIPE)
			node = node->next;
		mini_sh->input->pid[i++] = exe_in_child(mini_sh, node, &cmd);
		while (node && node->type != OP_PIPE)
			node = node->next;
		(clear_cmd(&cmd), my_close(&pipe1), my_close(&pipe2[WRITE_END]));
		pipe1 = pipe2[READ_END];
	}
	my_close(&pipe1);
	mini_sh->exit_code = wait_children(mini_sh->input);
}
