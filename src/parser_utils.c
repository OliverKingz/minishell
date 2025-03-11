/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:34:59 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/11 17:27:44 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_quotes(t_shell *mini_sh, char *current, int i[2], int *state)
{
	// if ((current[i[1]] == '\'' && current[i[1] + 1] == '\'')
	// 	|| (current[i[1]] == '\"' && current[i[1] + 1] == '\"'))
	// 	i[0] = i[1] + 2;
	// else 
	if (current[i[1]] == '\'' && *state != D_QUOTE)
	{
		if (*state == WORD)
			*state = S_QUOTE, i[0] = i[1];
		else if (*state == S_QUOTE)
		{
			if (ft_isspace(current[i[1] + 1]) || current[i[1] + 1] == '\0')
			{
				addback_token(mini_sh, ft_substr(current, i[0] + 1, i[1] - i[0] - 1),
					WORD);
				*state = WORD;
				i[0] = i[1] + 1;
			}
		}
	}
	else if (current[i[1]] == '\"' && *state != S_QUOTE)
	{
		if (*state == WORD)
			*state = D_QUOTE, i[0] = i[1];
		else if (*state == D_QUOTE)
		{
			*state = WORD;
			if (ft_isspace(current[i[1] + 1]) || current[i[1] + 1] == '\0')
			{
				addback_token(mini_sh, ft_substr(current, i[0] + 1, i[1] - i[0] - 1),
					WORD);
				i[0] = i[1] + 1;
			}
		}
	}
}

void	handle_redir(t_shell *mini_sh, char *current, int i[2], int *state)
{
	if ((*state == WORD) && (current[i[1]] == '>' || current[i[1]] == '<'))
	{
		if (i[1] > i[0])
			addback_token(mini_sh, ft_substr(current, i[0], i[1] - i[0]), WORD);
		if (current[i[1]] == '>' && current[i[1] + 1] == '>')
		{
			addback_token(mini_sh, ft_strdup(">>"), REDIR_APP), i[0] = i[1] + 2;
			i[1]++;
		}
		else if (current[i[1]] == '<' && current[i[1] + 1] == '<')
		{
			addback_token(mini_sh, ft_strdup("<<"), REDIR_HD), i[0] = i[1] + 2;
			i[1]++;
		}
		else if (current[i[1]] == '>')
			addback_token(mini_sh, ft_strdup(">"), REDIR_OUT), i[0] = i[1] + 1;
		else if (current[i[1]] == '<')
			addback_token(mini_sh, ft_strdup("<"), REDIR_IN), i[0] = i[1] + 1;
	}
}

void	handle_pipe_space(t_shell *mini_sh, char *current, int i[2], int *state)
{
	if (current[i[1]] == '|' && *state == WORD)
	{
		if (i[1] > i[0])
			addback_token(mini_sh, ft_substr(current, i[0], i[1] - i[0]), WORD);
		addback_token(mini_sh, ft_strdup("|"), OP_PIPE);
		i[0] = i[1] + 1;
	}
	else if (*state == WORD && ft_isspace(current[i[1]]))
	{
		if (i[1] > i[0])
			addback_token(mini_sh, ft_substr(current, i[0], i[1] - i[0]), WORD);
		i[0] = i[1] + 1;
	}
}
