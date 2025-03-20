/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:50:51 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/20 15:57:28 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execution(t_shell *mini_sh)
{
	t_builtin	bi_cmd;

	print_tokenslist_short(mini_sh->input->token_lst);
	bi_cmd = is_bi(mini_sh->input->token_lst);
	if (mini_sh->input->pipe_count == 0 && bi_cmd)
		exec_one_bi(mini_sh, bi_cmd);
	else
		execute_cmds(mini_sh);
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

pid_t	exe_in_child(t_shell *mini_sh, t_token *node, t_cmd *cmd)
{
	pid_t	pid;
	t_token	*cmd_node;
	int		bi_exit_code;

	pid = fork();
	if (pid != 0)
		return (pid);
	if (man_redirections(node, cmd))
		cmd_exit_and_clean(mini_sh, cmd, 1);
	dup2(cmd->in_fd, STDIN_FILENO);
	dup2(cmd->out_fd, STDOUT_FILENO);
	cmd_close_all_fd(cmd);
	cmd_node = get_token_type(node, COMMAND);
	if (!cmd_node)
		(clear_cmd(cmd), free_shell(mini_sh), exit(0));
	cmd_not_found(mini_sh, cmd);
	cmd->is_bi = is_bi(cmd_node);
	if (!cmd->is_bi)
		execve(cmd->cmd_path, cmd->cmd_args, cmd->env);
	bi_exit_code = exec_bi(mini_sh, cmd, cmd->is_bi);
	cmd_exit_and_clean(mini_sh, cmd, bi_exit_code);
	return (bi_exit_code);
}

int	wait_children(t_input *input)
{
	int	exit_code;
	int	status;
	int	i;

	i = 0;
	status = 0;
	signal(SIGINT, SIG_IGN);
	while (i < input->pipe_count + 1)
	{
		if (input->pid[i] != -1)
			waitpid(input->pid[i], &status, 0);
		i++;
	}
	signal(SIGINT, handle_ctrl_c);
	if (WIFSIGNALED(status))
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		exit_code = WTERMSIG(status) + 128;
		return (exit_code);
	}
	exit_code = WEXITSTATUS(status);
	return (exit_code);
}
