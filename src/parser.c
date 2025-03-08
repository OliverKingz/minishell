/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:53:53 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/08 01:59:00 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_redir(t_shell *mini_sh, char *current, int *start, int *i)
{
	if (current[*i] == '>' && current[*i + 1] == '>')
	{
		addback_token(mini_sh, ft_strdup(">>"), REDIR_APP);
		*start = *i + 2;
		(*i)++;
	}
	else if (current[*i] == '<' && current[*i + 1] == '<')
	{
		addback_token(mini_sh, ft_strdup("<<"), REDIR_HD);
		*start = *i + 2;
		(*i)++;
	}
	else if (current[*i] == '>')
	{
		addback_token(mini_sh, ft_strdup(">"), REDIR_OUT);
		*start = *i + 1;
	}
	else if (current[*i] == '<')
	{
		addback_token(mini_sh, ft_strdup("<"), REDIR_IN);
		*start = *i + 1;
	}
}

void	handle_pipe_space(t_shell *mini_sh, char *current, int *start, int *i)
{
	if (current[*i] == '|')
	{
		addback_token(mini_sh, ft_strdup("|"), OP_PIPE);
		*start = *i + 1;
	}
	else if (current[*i] == ' ' || current[*i] == '\t' || current[*i] == '\n')
	{
		if (*i > *start)
			addback_token(mini_sh, ft_substr(current, *start, *i - *start), WORD);
		*start = *i + 1;
	}
}

void	tokenize(t_shell *mini_sh)
{
	int		i;
	int		start;
	char	*current;

	current = mini_sh->input->read_line;
	start = 0;
	i = 0;
	while (current[i] != '\0')
	{
		//handle_quotes(mini_sh, current, &start, &i);
		handle_redir(mini_sh, current, &start, &i);
		handle_pipe_space(mini_sh, current, &start, &i);
		//handle_others(mini_sh, current, &start, &i); //Mirar prev para etiquetar arg, file, limiter, command
		//En others, leer la lista y taggear files los van despues de redir
		//Taggear como command si head, o despues de pipe
		//Taggear como arg todos los words despues de command, saltandose las Redir y Files
		i++;
	}
	addback_token(mini_sh, ft_substr(current, start, i - start), WORD);
}
