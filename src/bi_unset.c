/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:19:04 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/18 21:09:28 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bi_unset(t_shell *mini_sh, t_cmd *cmd)
{
	int	exit_code;
	int	i;

	exit_code = EXIT_SUCCESS;
	if (!cmd->cmd_args[1])
		return (exit_code);
	i = 1;
	while (cmd->cmd_args[i])
	{
		remove_envnode(&(mini_sh->env), cmd->cmd_args[i]);
		i++;
	}
	return (exit_code);
}
