/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:03:23 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/22 23:35:12 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export(t_env *start)
{
	t_env	*current;

	current = start;
	while (current)
	{
		if (current->value != NULL)
			printf("%s=\"%s\"\n", current->name, current->value);
		else
			printf("%s\n", current->name);
		current = current->next;
	}
}

int	bi_export(t_shell *mini_sh, t_cmd *cmd)
{
	char	*err;
	int		exit_code;
	int		i;

	exit_code = EXIT_SUCCESS;
	if (!cmd->cmd_args[1])
		return (print_export(mini_sh->env), exit_code);
	i = 1;
	while (cmd->cmd_args[i])
	{
		if (is_valid_var_name(cmd->cmd_args[i]))
			register_var(mini_sh, cmd->cmd_args[i]);
		else
		{
			err = my_strjoin3("export: ", cmd->cmd_args[i], ERR_ID);
			ft_puterr(err);
			my_free((void **)&err);
			exit_code = EXIT_FAILURE;
		}
		i++;
	}
	return (exit_code);
}
