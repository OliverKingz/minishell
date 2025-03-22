/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:22:30 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/22 17:27:27 by ozamora-         ###   ########.fr       */
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
	return (NULL);
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
	env = (char **)ft_calloc(i + 1, sizeof(char *));
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

void	init_emergency_env(t_shell *mini_sh)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		add_var(mini_sh, ft_strdup("PWD"), ft_strdup(cwd));
	else
		perror("env: getcwd");
}

void	increase_shlvl(t_shell *mini_sh)
{
	int		shlvl;
	char	*shlvl_str;

	shlvl_str = my_getenv(mini_sh->env, "SHLVL");
	if (!shlvl_str)
		return (add_var(mini_sh, ft_strdup("SHLVL"), ft_strdup("1")));
	shlvl = ft_atoi(shlvl_str);
	if (shlvl < 0)
		shlvl = 0;
	else
		shlvl = shlvl + 1;
	update_var(mini_sh, ft_strdup("SHLVL"), ft_itoa(shlvl));
}
