/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:25:35 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/25 18:23:03 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	validate_rline_syntax(char *read_line)
{
	char	*current;
	int		s_quote_count;
	int		d_quote_count;
	int		i;

	current = read_line;
	s_quote_count = 0;
	d_quote_count = 0;
	i = 0;
	while (ft_isspace(current[i]))
		i++;
	if (current[i] == '|')
		return (ft_puterr(ERR_SYNTAX_PP), false);
	i = -1;
	while (current[++i] != '\0')
	{
		if (!check_syntax_quotes(current, i, &s_quote_count, &d_quote_count))
			return (false);
	}
	if (current[i - 1] == '|' || current[i - 1] == '>' || current[i - 1] == '<')
		return (ft_puterr(ERR_SYNTAX_NL), false);
	if ((s_quote_count % 2) == 1 || (d_quote_count % 2) == 1)
		return (ft_puterr(ERR_SYNTAX), false);
	return (true);
}

bool	check_syntax_quotes(char *current, int i, int *s_quote_count,
		int *d_quote_count)
{
	bool	in_s_quote;
	bool	in_d_quote;

	in_s_quote = false;
	in_d_quote = false;
	if (current[i] == '\'' && !in_d_quote && (*d_quote_count % 2) == 0)
	{
		in_s_quote = !in_s_quote;
		(*s_quote_count)++;
	}
	if (current[i] == '\"' && !in_s_quote && (*s_quote_count % 2) == 0)
	{
		in_d_quote = !in_d_quote;
		(*d_quote_count)++;
	}
	return (true);
}

static bool	is_next_token_symbol(t_token *current)
{
	if ((!current->next || (current->next->type >= OP_PIPE
				&& current->next->type <= REDIR_APP)))
		return (true);
	return (false);
}

bool	validate_tokens_syntax(t_shell *mini_sh)
{
	t_token	*current;

	current = mini_sh->input->token_lst;
	while (current != NULL)
	{
		if ((current->type == OP_PIPE
				&& (!current->next || current->next->type == OP_PIPE))
			|| (current->type == REDIR_IN && is_next_token_symbol(current))
			|| (current->type == REDIR_OUT && is_next_token_symbol(current))
			|| (current->type == REDIR_HD && is_next_token_symbol(current))
			|| (current->type == REDIR_APP && is_next_token_symbol(current)))
		{
			mini_sh->exit_code = 2;
			return (ft_puterr(ERR_SYNTAX), false);
		}
		current = current->next;
	}
	return (true);
}
