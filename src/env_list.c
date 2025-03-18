/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:08:08 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/18 21:08:51 by ozamora-         ###   ########.fr       */
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
		my_free((void **)&(node->name));
		my_free((void **)&(node->value));	
		my_free((void **)&node);
		node = next_node;
	}
	*start = NULL;
}

void	remove_envnode(t_env **start, char *name)
{
	t_env	*current;
	t_env	*previous;

	current = *start;
	previous = NULL;
	while (current != NULL)
	{
		if (ft_strncmp(current->name, name, -1) == 0)
		{
			if (previous == NULL)
				*start = current->next;
			else
				previous->next = current->next;
			my_free((void **)&(current->name));
			my_free((void **)&(current->value));
			my_free((void **)&current);
			return ;
		}
		previous = current;
		current = current->next;
	}
}
