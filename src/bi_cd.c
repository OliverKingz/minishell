/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:10:58 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/20 23:35:52 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_directory(char *route)
{
	struct stat	info;

	stat(route, &info);
	return (S_ISDIR(info.st_mode));
}

int	bi_cd(t_shell *mini_sh, t_cmd *cmd)
{
	int	exit_code;
	char	*path;
	char	cwd[PATH_MAX];

	exit_code = EXIT_SUCCESS;
	if (cmd->cmd_argc == 1)
	{
		path = my_getenv(mini_sh->env, "HOME");
		if (!path)
			return (ft_puterr("cd: HOME not set\n"), EXIT_FAILURE);
	}
	else if (ft_strncmp(cmd->cmd_args[1], "-", -1) == 0)
	{
		path = my_getenv(mini_sh->env, "OLDPWD");
		if (!path)
			return (ft_puterr("cd: OLDPWD not set\n"), EXIT_FAILURE);
		printf("%s\n", path);
	}
	else
		path = cmd->cmd_args[1];
	if (chdir(path) < 0)
		return (my_perr("cd", false, 1), EXIT_FAILURE);
	return (exit_code);
}
