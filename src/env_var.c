/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:48:00 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/24 11:56:13 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_var_name(const char *argv)
{
	char	*name;
	int		eq_pos;
	int		i;

	if (!argv || ft_strlen(argv) <= 0 || argv[0] == '=')
		return (false);
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

void	register_var(t_shell *mini_sh, const char *argv)
{
	char	*name;
	char	*value;
	int		eq_pos;

	if (!argv)
		return ;
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
	if (!update_var(mini_sh, name, value))
		add_var(mini_sh, name, value);
}

bool	update_var(t_shell *mini_sh, char *name, char *value)
{
	t_env	*current;

	current = mini_sh->env;
	while (current != NULL)
	{
		if (ft_strncmp(current->name, name, -1) == 0)
		{
			(my_free((void **)&(current->value)), my_free((void **)&(name)));
			current->value = value;
			return (true);
		}
		current = current->next;
	}
	return (false);
}

void	add_var(t_shell *mini_sh, char *name, char *value)
{
	addback_envnode(&(mini_sh->env), create_envnode(name, value));
}
