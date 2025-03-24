/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:32:05 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/22 23:48:21 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_token(char *content, t_type token_type)
{
	t_token	*node;

	node = ft_calloc(1, sizeof(t_token));
	if (!node)
		return (ft_puterr("token node calloc"), NULL);
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
			my_free((void **)&(current->content));
		my_free((void **)&current);
		current = next;
	}
	*token_lst = NULL;
}
