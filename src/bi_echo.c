/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:01:51 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/19 00:35:13 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bi_echo(t_shell *mini_sh, t_cmd *cmd)
{
	bool	n_flag;
	int		i;

	(void)mini_sh;
	i = 1;
	n_flag = false;
	if (cmd->cmd_args[1] && ft_strncmp(cmd->cmd_args[1], "-n", -1) == 0)
	{
		n_flag = true;
		i++;
	}
	while (cmd->cmd_args[i])
	{
		ft_putstr_fd(cmd->cmd_args[i], STDOUT_FILENO);
		if (cmd->cmd_args[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	if (n_flag == false)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
