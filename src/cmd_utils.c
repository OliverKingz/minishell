/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:58:06 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/25 18:02:39 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_file(char *route)
{
	struct stat	info;

	stat(route, &info);
	return (S_ISREG(info.st_mode));
}

char	*locate_cmd(t_shell *mini_sh, t_token *node)
{
	char	*name;
	char	*temp;
	char	**path;
	int		i;

	node = get_token_type(node, COMMAND);
	if (!node)
		return (NULL);
	name = node->content;
	if (strchr(name, '/') || (access(name, X_OK) == 0 && is_file(name))
		|| is_bi(node))
		return (ft_strdup(name));
	path = ft_split(my_getenv(mini_sh->env, "PATH"), ':');
	i = 0;
	while (path && path[i])
	{
		temp = ft_strjoin_char(path[i], name, '/');
		if (!temp || access(temp, X_OK) != 0 || !is_file(temp))
			my_free((void **)&temp);
		else
			return (my_free2d((void ***) &path), temp);
		i++;
	}
	my_free2d((void ***) &path);
	return (NULL);
}

t_cmd	init_cmd(t_shell *mini_sh, t_token *node, int *pipe1, int *pipe2)
{
	t_cmd	cmd;

	cmd.in_fd = STDIN_FILENO;
	cmd.out_fd = STDOUT_FILENO;
	cmd.close_fd = -1;
	if (pipe1 && node->type == OP_PIPE)
	{
		cmd.in_fd = *pipe1;
		node = node->next;
	}
	if (pipe2 && get_token_type(node, OP_PIPE))
	{
		pipe(pipe2);
		cmd.out_fd = pipe2[WRITE_END];
		cmd.close_fd = pipe2[READ_END];
	}
	cmd.cmd_path = locate_cmd(mini_sh, node);
	cmd.cmd_args = get_args(node);
	cmd.cmd_argc = count_token_type(node, CMD_ARG) + 1;
	cmd.env = envlist_to_str(mini_sh->env);
	cmd.is_bi = 0;
	return (cmd);
}

void	clear_cmd(t_cmd *cmd)
{
	my_free((void **)&(cmd->cmd_path));
	my_free2d((void ***) &(cmd->cmd_args));
	my_free2d((void ***) &(cmd->env));
}

void	cmd_not_found(t_shell *mini_sh, t_cmd *cmd)
{
	char	*err;

	if (cmd->cmd_path)
		return ;
	err = ft_strjoin(cmd->cmd_args[0], ERR_COMMAND);
	ft_puterr(err);
	my_free((void **)&err);
	cmd_exit_and_clean(mini_sh, cmd, 127);
}
