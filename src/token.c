/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:42:48 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/07 22:53:41 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_token(char *content, t_type token_type)
{
	t_token	*node;

	node = malloc(sizeof(t_token));
	if (!node)
		return (NULL);
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
	return (mini_sh->input->token_lst);
}

void	print_tokenslist(t_token *token_lst)
{
	const char	*type_strings[] = {"WORD", "COMMAND", "ARG", "OP_PIPE",
			"REDIR_IN", "REDIR_OUT", "REDIR_APP", "REDIR_HD", "FILE_PATH",
			"LIMITER"};
	t_token		*current;

	current = token_lst;
	while (current != NULL)
	{
		ft_printf("Token Content: %s\n", current->content);
		ft_printf("Token Type: %s\n", type_strings[current->type]);
		ft_printf("Token Index: %d\n", current->index);
		ft_printf("_________________________________\n");
		current = current->next;
	}
}

// USA FUNCION PROHIBIDA PRINTF!
void	print_tokenslist_short(t_token *token_lst)
{
	const char	*type_strings[] = {"WORD", "COMMAND", "ARG", "OP_PIPE",
			"REDIR_IN", "REDIR_OUT", "REDIR_APP", "REDIR_HD", "FILE_PATH",
			"LIMITER"};
	t_token		*current;

	current = token_lst;
	while (current != NULL)
	{
		printf("[%-9s]", current->content);
		if (current->next != NULL)
			printf("→");
		current = current->next;
	}
	printf("\n");
	current = token_lst;
	while (current != NULL)
	{
		printf("[%-9s]", type_strings[current->type]);
		if (current->next != NULL)
			printf("→");
		current = current->next;
	}
	printf("\n─────────────────────────────────────────────────────\n");
}

void	clear_tokenlist(t_token **token_lst)
{
	t_token *current;
	t_token *next;

	if (!token_lst)
		return ;
	current = *token_lst;
	while (current != NULL)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*token_lst = NULL;
}