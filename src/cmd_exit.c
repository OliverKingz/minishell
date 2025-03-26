/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:53:47 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/26 02:28:16 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	cmd_exit_and_clean(t_shell *shell, t_cmd *cmd, int exit_code)
{
	free_shell(shell);
	my_close(&(cmd->in_fd));
	my_close(&(cmd->out_fd));
	clear_cmd(cmd);
	if (exit_code != -1)
		exit(exit_code);
}

void	cmd_close_all_fd(t_cmd *cmd)
{
	my_close(&(cmd->close_fd));
	my_close(&(cmd->in_fd));
	my_close(&(cmd->out_fd));
}
