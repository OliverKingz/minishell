/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:08:08 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/08 15:21:44 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envnode	*create_envnode(char *name, char *value)
{
	t_envnode	*node;

	node = ft_calloc(1, sizeof(t_envnode));
	if (!node)
		return (NULL);
	node->name = name;
	node->value = value;
	node->next = NULL;
	return (node);
}

void	addback_envnode(t_envnode **start, t_envnode *node)
{
	t_envnode	*temp;

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

int	ft_strchr_pos(const char *s, char c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	init_envlist(char **env, t_envnode **start)
{
	t_envnode	*node;
	int			i;
	char		*name;
	char		*value;

	if (!start)
		return ;
	if (!env)
		*start = NULL;
	node = *start;
	while (*env)
	{
		i = ft_strchr_pos(*env, '=');
		name = ft_substr(*env, 0, i);
		value = ft_substr(*env, i + 1, -1);
		node = create_envnode(name, value);
		addback_envnode(start, node);
		env++;
	}
}

char	*my_getenv(t_envnode *start, char *name)
{
	if (!name)
		return (NULL);
	while(start)
	{
		if (ft_strncmp(start->name, name, -1) == 0)
			return(start->value);
		start = start->next;
	}
	return (NULL);
}

void	clear_envnode(t_envnode	*node)
{
	if (!node)
		return ;
	free(node->name);
	free(node->value);
}

void	clear_envlist(t_envnode **start)
{
	t_envnode	*node;
	t_envnode	*next_node;

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
