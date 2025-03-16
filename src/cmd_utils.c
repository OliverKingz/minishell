/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:58:06 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/16 12:38:08 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if (access(name, X_OK) == 0)
		return (ft_strdup(name));
	path = ft_split(my_getenv(mini_sh->env, "PATH"), ':');
	i = 0;
	while (path && path[i])
	{
		temp = ft_strjoin_char(path[i], name, '/');
		if (!temp || access(temp, X_OK) != 0)
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
	if (node->type == OP_PIPE)
	{
		cmd.in_fd = *pipe1;
		node = node->next;
	}
	if (get_token_type(node, OP_PIPE))
	{
		pipe(pipe2);
		cmd.out_fd = pipe2[WRITE_END];
		cmd.close_fd = pipe2[READ_END];
	}
	cmd.cmd_path = locate_cmd(mini_sh, node);
	cmd.cmd_args = get_args(node);
	cmd.env = envlist_to_str(mini_sh->env);
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
	char	*s;

	s = ft_strjoin(cmd->cmd_args[0], ERR_COMMAND);
	ft_putstr_fd(s, STDERR_FILENO);
	my_free((void **)&s);
	clear_cmd(cmd);
	free_shell(mini_sh);
	exit(127);
}
