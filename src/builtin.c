/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:13:25 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/21 14:58:52 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_bi(t_token *node)
{
	if (ft_strncmp(node->content, "echo", -1) == 0)
		return (BI_ECHO);
	else if (ft_strncmp(node->content, "pwd", -1) == 0)
		return (BI_PWD);
	if (ft_strncmp(node->content, "env", -1) == 0)
		return (BI_ENV);
	if (ft_strncmp(node->content, "cd", -1) == 0)
		return (BI_CD);
	if (ft_strncmp(node->content, "export", -1) == 0)
		return (BI_EXPORT);
	if (ft_strncmp(node->content, "unset", -1) == 0)
		return (BI_UNSET);
	if (ft_strncmp(node->content, "exit", -1) == 0)
		return (BI_EXIT);
	return (NO_BI);
}

int	exec_bi(t_shell *mini_sh, t_cmd *cmd, t_builtin bi_cmd)
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	if (bi_cmd == BI_ECHO)
		exit_code = bi_echo(mini_sh, cmd);
	else if (bi_cmd == BI_PWD)
		exit_code = bi_pwd(mini_sh, cmd);
	else if (bi_cmd == BI_ENV)
		exit_code = bi_env(mini_sh, cmd);
	else if (bi_cmd == BI_CD)
		exit_code = bi_cd(mini_sh, cmd);
	else if (bi_cmd == BI_EXPORT)
		exit_code = bi_export(mini_sh, cmd);
	else if (bi_cmd == BI_UNSET)
		exit_code = bi_unset(mini_sh, cmd);
	else if (bi_cmd == BI_EXIT)
		exit_code = bi_exit(mini_sh, cmd);
	return (exit_code);
}

void	exec_one_bi(t_shell *mini_sh, t_builtin bi_cmd)
{
	t_cmd	cmd;
	int		savefd[2];

	cmd = init_cmd(mini_sh, mini_sh->input->token_lst, NULL, NULL);
	if (!handle_redirections(mini_sh->input->token_lst, &cmd))
	{
		savefd[0] = dup(STDIN_FILENO);
		savefd[1] = dup(STDOUT_FILENO);
		dup2(cmd.in_fd, STDIN_FILENO);
		dup2(cmd.out_fd, STDOUT_FILENO);
		cmd_close_all_fd(&cmd);
		mini_sh->exit_code = exec_bi(mini_sh, &cmd, bi_cmd);
		dup2(savefd[0], STDIN_FILENO);
		dup2(savefd[1], STDOUT_FILENO);
		my_close(&savefd[0]);
		my_close(&savefd[1]);
	}
	else
		mini_sh->exit_code = 1;
	clear_cmd(&cmd);
}
