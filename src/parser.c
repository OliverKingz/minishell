/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:53:53 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/08 18:17:29 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_redir(t_shell *mini_sh, char *current, int i[2], int *state)
{
	if (current[i[1]] == '>' && current[i[1] + 1] == '>' && *state == WORD)
	{
		addback_token(mini_sh, ft_strdup(">>"), REDIR_APP);
		i[0] = i[1] + 2;
		i[1]++;
	}
	else if (current[i[1]] == '<' && current[i[1] + 1] == '<' && *state == WORD)
	{
		addback_token(mini_sh, ft_strdup("<<"), REDIR_HD);
		i[0] = i[1] + 2;
		i[1]++;
	}
	else if (current[i[1]] == '>' && *state == WORD)
	{
		addback_token(mini_sh, ft_strdup(">"), REDIR_OUT);
		i[0] = i[1] + 1;
	}
	else if (current[i[1]] == '<' && *state == WORD)
	{
		addback_token(mini_sh, ft_strdup("<"), REDIR_IN);
		i[0] = i[1] + 1;
	}
}

void	handle_pipe_space(t_shell *mini_sh, char *current, int i[2], int *state)
{
	if (current[i[1]] == '|' && *state == WORD)
	{
		addback_token(mini_sh, ft_strdup("|"), OP_PIPE);
		i[0] = i[1] + 1;
	}
	else if (current[i[1]] == ' ' || current[i[1]] == '\t' || current[i[1]] == '\n')
	{
		if (i[1] > i[0] && *state == WORD)
			addback_token(mini_sh, ft_substr(current, i[0], i[1] - i[0]), WORD);
		i[0] = i[1] + 1;
	}
}

void	tokenize(t_shell *mini_sh)
{
	int		i[2];
	int		state;
	char	*current;

	current = mini_sh->input->read_line;
	i[0] = 0;
	i[1] = 0;
	state = WORD;
	while (current[i[1]] != '\0')
	{
		// handle_quotes(mini_sh, current, i, &state);
			//var_expansion para caso ""
		handle_redir(mini_sh, current, i, &state);
		handle_pipe_space(mini_sh, current, i, &state);
		// handle_var_expansion //caso fuera de ""
		// handle_others(mini_sh, current, i, &state);
			//Mirar prev para etiquetar arg, file, limiter, command
		// En others, leer la lista y taggear files los van despues de redir
		// Taggear como command si word&head, o despues de pipe (correcto)
		// Taggear como arg todos los words despues de command, saltandose las Redir y Files
		// Caso echo hola | <<EOF cat -e (R: poner booleano si ya has puesto el comando)
		i[1]++;
	}
	addback_token(mini_sh, ft_substr(current, i[0], i[1] - i[0]), WORD);
}
