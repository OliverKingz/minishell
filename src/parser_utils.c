/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:34:59 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/14 12:02:58 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_quotes(t_shell *mini_sh, char *current, int i[2], int *state)
{	
	(void)mini_sh;
	// if (*state == WORD
	// 	&& (i[1] > i[0]) && (current[i[1]] == '\'' || current[i[1]] == '\"')) // Revisar 
	// 	addback_token(mini_sh, ft_substr(current, i[0], i[1] - i[0]), WORD);
	if (current[i[1]] == '\'' && *state != D_QUOTE)
	{
		if (*state == WORD)
		{
			*state = S_QUOTE;
			//i[0] = i[1]; // Dejar las comillas
		}
		else if (*state == S_QUOTE)
		{
			// if (i[1] - i[0] > 0)
			// 	addback_token(mini_sh, ft_substr(current, i[0], i[1] - i[0] + 1), WORD); //Dejar comillas
			*state = WORD;
			//i[0] = i[1] + 1;
			// if (current[i[1] + 1] == '\'' || current[i[1] + 1] == '\'')
			// 	i[0] = i[1] + 1; 
		}
	}
	else if (current[i[1]] == '\"' && *state != S_QUOTE)
	{
		if (*state == WORD)
		{
			*state = D_QUOTE;
			//i[0] = i[1]; // Dejar comillas
		}
		else if (*state == D_QUOTE)
		{
			// if (i[1] - i[0] > 0)
			// 	addback_token(mini_sh, ft_substr(current, i[0], i[1] - i[0] + 1), WORD);//Dejar comillas
			*state = WORD;
			//i[0] = i[1] + 1;
			// if (current[i[1] + 1] == '\"' || current[i[1] + 1] == '\"') //
			// 	i[0] = i[1] + 1; 
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

void	remove_chr_pos(char *s, int pos)
{
	int		len;

	if (!s)
		return ;
	len = ft_strlen(s);
	if (pos >= len)
		return ;
	ft_memmove(&s[pos], &s[pos + 1], ft_strlen(&s[pos]));
}

void	remove_external_quotes(char *s)
{
	int		i;
	char	quote;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			quote = s[i];
			remove_chr_pos(s, i);
			while (s[i] && s[i] != quote)
				i++;
			remove_chr_pos(s, i);
			i--;
		}
		i++;
	}
}

/*
int main(void)
{
	char s[] = "\"\'\'\"Hola";

	remove_external_quotes(s);
	printf("%s\n", s);
	return (0);
}*/