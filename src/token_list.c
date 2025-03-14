/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/14 23:04:20 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





#include "minishell.h"

t_token	*create_token(char *content, t_type token_type)
{
	t_token	*node;

	node = ft_calloc(1, sizeof(t_token));
	if (!node)
		return (my_perr("create_tokennode", false, errno), NULL);
	node->content = content;
	node->type = token_type;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	addback_token(t_shell *mini_sh, char *content, t_type token_type)
{
	t_token	*node;
	t_token	*temp;
	int		index;

	index = 0;
	node = create_token(content, token_type);
	if (!node)
	{
		(free_shell(mini_sh), exit(errno));
		return ;
	}
	if (!mini_sh->input->token_lst)
	{
		node->index = index;
		mini_sh->input->token_lst = node;
		return ;
	}
	temp = mini_sh->input->token_lst;
	while (temp->next)
	{
		temp = temp->next;
		index++;
	}
	node->index = index + 1;
	temp->next = node;
}

t_token	*init_tokenlist(t_shell *mini_sh)
{
	mini_sh->input->token_lst = NULL;
	tokenize(mini_sh);
	if (!validate_tokens_syntax(mini_sh))
		return (clear_tokenlist(&(mini_sh->input->token_lst)), NULL);
	return (mini_sh->input->token_lst);
}

void	clear_tokenlist(t_token **token_lst)
{
	t_token	*current;
	t_token	*next;

	if (!token_lst)
		return ;
	current = *token_lst;
	while (current != NULL)
	{
		next = current->next;
		if (current->content)
			(free(current->content), current->content = NULL);
		(free(current), current = NULL);
		current = next;
	}
	*token_lst = NULL;
}

/*Devuelve el primer token del tipo específicado.
Chequea hasta que llega a un pipe o al final de la lista*/
t_token	*get_token_type(t_token *node, t_type type)
{
	while (node && node->type != OP_PIPE)
	{
		if (node->type == type)
			return (node);
		node = node->next;
	}
	return (NULL);
}

/*Devuelve un array de strings con cada uno de los argumentos
desde el nodo inicial hasta un pipe o el final. El propio comando
es el argumento 0 (necesario para execve).
*/
char	**get_args(t_token *node)
{
	char	**args;
	int		argc;
	int		i;

	argc = count_token_type(node, COMMAND) + 1;
	args = ft_calloc(argc + 1, sizeof(char *));
	i = 0;
	while (node && node->type != OP_PIPE)
	{
		if (node->type == COMMAND || node->type == ARG)
			args[i++] = ft_strdup(node->content);
		node = node->next;
	}
	args[i] = NULL;
	return (args);
}

/*Devuelve el número de nodos del tipo especificado
hasta que encuentre un pipe o se llegue al final
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
