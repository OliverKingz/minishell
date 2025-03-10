/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:08:08 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/10 16:00:35 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*create_envnode(char *name, char *value)
{
	t_env	*node;

	node = ft_calloc(1, sizeof(t_env));
	if (!node)
		return (my_perr("create_envnode", false, errno), NULL);
	node->name = name;
	node->value = value;
	node->next = NULL;
	return (node);
}

void	addback_envnode(t_env **start, t_env *node)
{
	t_env	*temp;

	if (!start)
		return ;
	if (!*start)
	{
		*start = node;
		return ;
	}
	temp = *start;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}

t_env	*init_envlist(char **env)
{
	t_env	*start;
	t_env	*node;
	int		i;
	char	*name;
	char	*value;

	if (!env)
		return (NULL);
	start = NULL;
	while (*env)
	{
		i = my_strchr_pos(*env, '=');
		name = ft_substr(*env, 0, i);
		value = ft_substr(*env, i + 1, -1);
		node = create_envnode(name, value);
		if (!node)
			return (NULL);
		addback_envnode(&start, node);
		env++;
	}
	return (start);
}

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

void	clear_envnode(t_env *node)
{
	if (!node)
		return ;
	free(node->name);
	free(node->value);
}

void	clear_envlist(t_env **start)
{
	t_env	*node;
	t_env	*next_node;

	if (!start)
		return ;
	node = *start;
	while (node)
	{
		next_node = node->next;
		clear_envnode(node);
		free(node);
		node = next_node;
	}
	*start = NULL;
}

void	print_envlist(t_env *start)
{
	while (start)
	{
		ft_putstr_fd(start->name, STDOUT_FILENO);
		ft_putchar_fd('=', STDOUT_FILENO);
		ft_putendl_fd(start->value, STDOUT_FILENO);
		start = start->next;
	}
}
