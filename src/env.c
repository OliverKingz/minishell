/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:25:14 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/14 15:26:24 by raperez-         ###   ########.fr       */
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
