/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:41:39 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/26 02:08:36 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_exit_error(char **args, int x)
{
	char	*err;

	err = NULL;
	if (x == 1)
		err = my_strjoin3("exit: ", args[1], ERR_ARG_INT);
	else if (x == 2)
		err = ft_strjoin("exit", ERR_ARGS);
	ft_puterr(err);
	my_free((void **)&err);
}

int	bi_exit(t_shell *mini_sh, t_cmd *cmd)
{
	int		exit_code;

	if (mini_sh->input->pipe_count == 0)
		printf("exit\n");
	if (cmd->cmd_argc == 1)
		exit_code = EXIT_SUCCESS;
	else if (cmd->cmd_argc == 2 && ft_issigned_nbr(cmd->cmd_args[1]))
		exit_code = my_atoi_circular(cmd->cmd_args[1], 0, 255);
	else
	{
		exit_code = 2;
		if (!ft_issigned_nbr(cmd->cmd_args[1]))
			handle_exit_error(cmd->cmd_args, 1);
		else
			return (handle_exit_error(cmd->cmd_args, 2), EXIT_FAILURE);
	}
	cmd_exit_and_clean(mini_sh, cmd, exit_code);
	return (exit_code);
}
