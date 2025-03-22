/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:25:14 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/22 17:26:17 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bi_env(t_shell *mini_sh, t_cmd *cmd)
{
	int		exit_code;
	char	*err;

	if (cmd->cmd_argc == 1)
	{
		exit_code = EXIT_SUCCESS;
		print_envlist(mini_sh->env);
	}
	else
	{
		exit_code = EXIT_FAILURE;
		err = ft_strjoin("env", ERR_ARGS);
		ft_putstr_fd(err, STDERR_FILENO);
		my_free((void **)&err);
	}
	return (exit_code);
}

void	print_envlist(t_env *start)
{
	while (start)
	{
		if (start->value != NULL)
		{
			ft_putstr_fd(start->name, STDOUT_FILENO);
			ft_putchar_fd('=', STDOUT_FILENO);
			ft_putendl_fd(start->value, STDOUT_FILENO);
		}
		start = start->next;
	}
}
