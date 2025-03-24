/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:10:58 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/24 13:05:39 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_directory(char *route)
{
	struct stat	info;

	stat(route, &info);
	return (S_ISDIR(info.st_mode));
}

char	*cd_set_path(t_shell *mini_sh, t_cmd *cmd)
{
	char	*path;

	if (cmd->cmd_argc == 1)
	{
		path = my_getenv(mini_sh->env, "HOME");
		if (!path)
			return (ft_puterr("cd: HOME not set\n"), NULL);
	}
	else if (ft_strncmp(cmd->cmd_args[1], "-", -1) == 0)
	{
		path = my_getenv(mini_sh->env, "OLDPWD");
		if (!path)
			return (ft_puterr("cd: OLDPWD not set\n"), NULL);
		printf("%s\n", path);
	}
	else if (cmd->cmd_argc > 2)
		return (ft_puterr("cd: too many argumets\n"), NULL);
	else
		path = cmd->cmd_args[1];
	return (path);
}

int	change_update_dir(t_shell *mini_sh, char *path)
{
	int		exit_code;
	char	cwd[PATH_MAX];
	char	*oldpwd;
	char	*pwd;

	oldpwd = NULL;
	pwd = NULL;
	exit_code = EXIT_SUCCESS;
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		oldpwd = ft_strjoin("OLDPWD=", cwd);
	else
		(perror("cd: getcwd"), exit_code = EXIT_FAILURE);
	if (chdir(path) < 0)
		(perror("cd"), exit_code = EXIT_FAILURE);
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		register_var(mini_sh, oldpwd);
		pwd = ft_strjoin("PWD=", cwd);
		register_var(mini_sh, pwd);
	}
	else
		(perror("cd: getcwd"), exit_code = EXIT_FAILURE);
	return (my_free((void **)&oldpwd), my_free((void **)&pwd), exit_code);
}

int	bi_cd(t_shell *mini_sh, t_cmd *cmd)
{
	int		exit_code;
	char	*path;

	exit_code = EXIT_SUCCESS;
	path = ft_strdup(cd_set_path(mini_sh, cmd));
	if (!path)
		return (EXIT_FAILURE);
	exit_code = change_update_dir(mini_sh, path);
	return (my_free((void **)&path), exit_code);
}
