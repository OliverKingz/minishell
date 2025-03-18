/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:53:47 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/18 11:55:23 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_exit_and_clean(t_shell *shell, t_cmd *cmd, int exit_status)
{
	free_shell(shell);
	my_close(&(cmd->in_fd));
	my_close(&(cmd->out_fd));
	clear_cmd(cmd);
	exit(exit_status);
}

void	cmd_close_all_fd(t_cmd *cmd)
{
	my_close(&(cmd->close_fd));
	my_close(&(cmd->in_fd));
	my_close(&(cmd->out_fd));
}
