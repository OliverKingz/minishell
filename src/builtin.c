/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:13:25 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/15 15:44:53 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_if_bi(t_token *node)
{
	size_t	len;

	len = ft_strlen(node->content);
	if (ft_strlen("echo") == len && ft_strncmp(node->content, "echo", len) == 0)
		return (BI_ECHO);
	else if (ft_strlen("pwd") == len && ft_strncmp(node->content, "pwd", len) == 0)
		return (BI_PWD);
	if (ft_strlen("env") == len && ft_strncmp(node->content, "env", len) == 0)
		return (BI_ENV);
	if (ft_strlen("cd") == len && ft_strncmp(node->content, "cd", len) == 0)
		return (BI_CD);
	if (ft_strlen("export") == len && ft_strncmp(node->content, "export",
			len) == 0)
		return (BI_EXPORT);
	if (ft_strlen("unset") == len && ft_strncmp(node->content, "unset",
			len) == 0)
		return (BI_UNSET);
	if (ft_strlen("exit") == len && ft_strncmp(node->content, "exit", len) == 0)
		return (BI_EXIT);
	return (BI_NO);
}

int	exec_bi(t_shell *mini_sh, t_builtin bi_cmd)
{
	int	exit_code;

	exit_code = 0;
	if (bi_cmd == BI_ECHO)
		exit_code = bi_echo(mini_sh);
	else if (bi_cmd == BI_PWD)
		exit_code = bi_pwd(mini_sh);
	else if (bi_cmd == BI_ENV)
		exit_code = bi_env(mini_sh);
	else if (bi_cmd == BI_CD)
		exit_code = bi_cd(mini_sh);
	else if (bi_cmd == BI_EXPORT)
		exit_code = bi_export(mini_sh);
	else if (bi_cmd == BI_UNSET)
		exit_code = bi_unset(mini_sh);
	else if (bi_cmd == BI_EXIT)
		exit_code = bi_exit(mini_sh);
	return (exit_code);
}

int	bi_pwd(t_shell *mini_sh)
{
	(void)mini_sh;
	return (EXIT_FAILURE);
}

int	bi_env(t_shell *mini_sh)
{
	(void)mini_sh;
	return (EXIT_FAILURE);
}

int	bi_cd(t_shell *mini_sh)
{
	(void)mini_sh;
	return (EXIT_FAILURE);
}

int	bi_export(t_shell *mini_sh)
{
	(void)mini_sh;
	return (EXIT_FAILURE);
}

int	bi_unset(t_shell *mini_sh)
{
	(void)mini_sh;
	return (EXIT_FAILURE);
}
