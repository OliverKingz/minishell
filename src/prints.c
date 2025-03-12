/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:20:15 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/12 16:29:29 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	print_tokenslist(t_token *token_lst)
{
	const char	*type_strings[] = {"WORD", "COMMAND", "ARG", "OP_PIPE",
			"REDIR_IN", "REDIR_OUT", "REDIR_HD", "REDIR_APP", "FILE_PATH",
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
			"REDIR_IN", "REDIR_OUT", "REDIR_HD", "REDIR_APP", "FILE_PATH",
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
