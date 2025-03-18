/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:53:47 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/18 23:37:25 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
