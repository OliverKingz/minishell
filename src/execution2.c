/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:49:09 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/25 22:16:14 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	safe_execve(t_shell *mini_sh, t_cmd *cmd)
{
	int	n;

	n = execve(cmd->cmd_path, cmd->cmd_args, cmd->env);
	if (n == -1)
	{
		perror(cmd->cmd_path);
		if (is_directory(cmd->cmd_path))
			cmd_exit_and_clean(mini_sh, cmd, 126);
		else
			cmd_exit_and_clean(mini_sh, cmd, 127);
	}
}
