/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:23:31 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/18 16:22:38 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Returns the first token of the specified type.
 * Checks until it reaches a pipe or the end of the list.
 *
 * @param node The starting node of the token list.
 * @param type The type of token to search for.
 * @return t_token* The first token of the specified type, or NULL if not found.
 */
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

/**
 * @brief Returns the first token with the specified content.
 * Checks until it reaches a pipe or the end of the list.
 *
 * @param node The starting node of the token list.
 * @param content The content of the token to search for.
 * @return t_token* The first token with the specified content,
	or NULL if not found.
 */
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

/**
 * @brief Returns an array of strings with each of the arguments
 * from the initial node to a pipe or the end. The command itself
 * is argument 0 (necessary for execve).
 *
 * @param node The starting node of the token list.
 * @return char** An array of strings representing the arguments.
 */
char	**get_args(t_token *node)
{
	char	**args;
	int		argc;
	int		i;

	argc = count_token_type(node, CMD_ARG);
	if (argc == 0 && !get_token_type(node, COMMAND))
		return (NULL);
	args = ft_calloc(argc + 2, sizeof(char *));
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

/**
 * @brief Returns the number of nodes of the specified type
 * until it finds a pipe or reaches the end.
 *
 * @param node The starting node of the token list.
 * @param type The type of token to count.
 * @return int The number of tokens of the specified type.
 */
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
