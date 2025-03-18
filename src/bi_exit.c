/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:41:39 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/18 19:33:36 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	my_atoi_circular(const char *nptr, int min, int max)
{
	int	nbr;
	int	range;

	nbr = ft_atoi(nptr);
	range = max - min + 1;
	if (nbr < min)
		nbr = nbr + range * ((min - nbr) / range + 1);
	else if (nbr > max)
		nbr = nbr - range * ((nbr - max) / range + 1);
	return (nbr);
}

void	handle_exit_error(char **args, int x)
{
	char	*s;

	s = NULL;
	if (x == 1)
		s = my_strjoin3("exit: ", args[1], ERR_ARG_INT);
	else if (x == 2)
		s = ft_strjoin("exit", ERR_ARGS);
	ft_putstr_fd(s, STDERR_FILENO);
	my_free((void **)&s);
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
			return (handle_exit_error(cmd->cmd_args, 2), 1);
	}
	cmd_exit_and_clean(mini_sh, cmd, exit_code);
	return (exit_code);
}
