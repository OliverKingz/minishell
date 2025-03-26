/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:23:31 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/26 02:44:26 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*get_token_type(t_token *node, t_type type)
{
	while (node)
	{
		if (node->type == type)
			return (node);
		if (node->type == OP_PIPE)
			break ;
		node = node->next;
	}
	return (NULL);
}

t_token	*get_token_content(t_token *node, char *content)
{
	size_t	len_content;

	len_content = ft_strlen(content);
	while (node)
	{
		if (ft_strlen(node->content) == len_content
			&& ft_strncmp(node->content, content, len_content) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

char	**get_args(t_token *node)
{
	char	**args;
	int		argc;
	int		i;

	argc = count_token_type(node, CMD_ARG);
	if (argc == 0 && !get_token_type(node, COMMAND))
		return (NULL);
	args = ft_calloc(argc + 2, sizeof(char *));
	if (!args)
		return (ft_puterr("get_args calloc"), NULL);
	i = 0;
	while (node && node->type != OP_PIPE)
	{
		if (node->type == COMMAND || node->type == CMD_ARG)
			args[i++] = ft_strdup(node->content);
		node = node->next;
	}
	args[i] = NULL;
	return (args);
}

int	count_token_type(t_token *node, t_type type)
{
	int	i;

	i = 0;
	while (node && node->type != OP_PIPE)
	{
		if (node->type == type)
			i++;
		node = node->next;
	}
	return (i);
}
