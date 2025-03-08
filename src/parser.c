/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:53:53 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/08 16:44:44 by raperez-         ###   ########.fr       */
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
	//int		state = S_QUOTE;

	current = mini_sh->input->read_line;
	start = 0;
	i = 0;
	while (current[i] != '\0')
	{
		//handle_quotes(mini_sh, current, &start, &i); //var_expansion para caso ""
		handle_redir(mini_sh, current, &start, &i);
		handle_pipe_space(mini_sh, current, &start, &i);
		//handle_var_expansion //caso fuera de ""
		//handle_others(mini_sh, current, &start, &i); //Mirar prev para etiquetar arg, file, limiter, command
		//En others, leer la lista y taggear files los van despues de redir
		//Taggear como command si word&head, o despues de pipe (correcto)
		//Taggear como arg todos los words despues de command, saltandose las Redir y Files 
		// Caso echo hola | <<EOF cat -e (R: poner booleano si ya has puesto el comando)
		i++;
	}
	addback_token(mini_sh, ft_substr(current, start, i - start), WORD);
}
