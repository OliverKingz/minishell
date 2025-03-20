/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:03:23 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/20 13:59:57 by raperez-         ###   ########.fr       */
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

int	is_valid_var_name(const char *argv)
{
	char	*name;
	int		eq_pos;
	int		i;

	eq_pos = my_strchr_pos(argv, '=');
	if (eq_pos == -1)
		name = ft_strdup(argv);
	else
		name = ft_substr(argv, 0, eq_pos);
	i = 0;
	while (name[i] != '\0')
	{
		if (!ft_isalpha(name[0]) && name[0] != '_')
			return (my_free((void **)&name), false);
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (my_free((void **)&name), false);
		i++;
	}
	my_free((void **)&name);
	return (true);
}

void	register_new_var(t_shell *mini_sh, const char *argv)
{
	char	*name;
	char	*value;
	int		eq_pos;

	eq_pos = my_strchr_pos(argv, '=');
	if (eq_pos == -1)
	{
		name = ft_strdup(argv);
		value = NULL;
	}
	else
	{
		name = ft_substr(argv, 0, eq_pos);
		value = ft_substr(argv, eq_pos + 1, -1);
	}
	update_or_add_var(mini_sh, name, value);
}

void	update_or_add_var(t_shell *mini_sh, char *name, char *value)
{
	t_env	*current;

	current = mini_sh->env;
	while (current != NULL)
	{
		if (ft_strncmp(current->name, name, -1) == 0)
		{
			(my_free((void **)&(current->value)), my_free((void **)&(name)));
			current->value = value;
			return ;
		}
		current = current->next;
	}
	addback_envnode(&(mini_sh->env), create_envnode(name, value));
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
			register_new_var(mini_sh, cmd->cmd_args[i]);
		else
		{
			err = my_strjoin3("export: ", cmd->cmd_args[i], ERR_ID);
			ft_putstr_fd(err, STDERR_FILENO);
			my_free((void **)&err);
			exit_code = EXIT_FAILURE;
		}
		i++;
	}
	return (exit_code);
}
