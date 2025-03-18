/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:25:14 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/18 19:42:29 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*my_getenv(t_env *start, char *name)
{
	if (!name)
		return (NULL);
	while (start)
	{
		if (ft_strncmp(start->name, name, -1) == 0)
			return (start->value);
		start = start->next;
	}
	return ("");
}

char	**envlist_to_str(t_env *start)
{
	char	**env;
	t_env	*node;
	int		i;

	if (!start)
		return (NULL);
	i = 0;
	node = start;
	while (node)
	{
		i++;
		node = node->next;
	}
	env = (char **) ft_calloc(i + 1, sizeof(char *));
	if (!env)
		return (NULL);
	i = 0;
	node = start;
	while (node)
	{
		env[i++] = ft_strjoin_char(node->name, node->value, '=');
		node = node->next;
	}
	return (env);
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

int	bi_env(t_shell *mini_sh, t_cmd *cmd)
{
	int		exit_code;

	if (cmd->cmd_argc == 1)
		exit_code = EXIT_SUCCESS, print_envlist(mini_sh->env);
	else
		(exit_code = EXIT_FAILURE, ft_puterr("env"), ft_puterr(ERR_ARGS));
	return (exit_code);
}
