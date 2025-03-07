/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:08:08 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/07 13:45:28 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envnode	*create_envnode(char *name, char *value)
{
	t_envnode *node;

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
		value = ft_substr(*env, i+1, -1);
		node = create_envnode(name, value);
		addback_envnode(start, node);
		env++;
	}
}

// void	clear_envnode(t_envnode	*)
// {
	
// }

// void	clear_envlist(t_envnode **start)
// {
// 	if (!start)
// 		return ;
// 	while ()
// }
