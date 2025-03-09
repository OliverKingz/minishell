/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:53:53 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/09 02:39:24 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		handle_quotes(mini_sh, current, i, &state);
		//handle_var_expansion(mini_sh, current, i, &state);
		handle_redir(mini_sh, current, i, &state);
		handle_pipe_space(mini_sh, current, i, &state);
		i[1]++;
	}
	if (i[1] > i[0])
		addback_token(mini_sh, ft_substr(current, i[0], i[1] - i[0]), WORD);
	classify_word_token(mini_sh);
}

void	classify_word_token(t_shell *mini_sh)
{
	t_token	*current;
	bool	single_cmd;
	int		last_type;

	last_type = WORD;
	single_cmd = false;
	current = mini_sh->input->token_lst;
	while (current != NULL)
	{
		classify_condition(current, &last_type, &single_cmd);
		current = current->next;
	}
}

void	classify_condition(t_token *current, int *last_type, bool *single_cmd)
{ //Preguntar caso <<1<<2<<3
	if (current->type == WORD)
	{
		if (*last_type == REDIR_IN || *last_type == REDIR_OUT
			|| *last_type == REDIR_APP)
			current->type = FILE_PATH;
		else if (*last_type == REDIR_HD)
			current->type = LIMITER;
		else if ((*last_type == OP_PIPE || *last_type == FILE_PATH 
			|| *last_type == LIMITER || current->index == 0)
			&& *single_cmd == false)
			current->type = COMMAND, *single_cmd = true;
		else if ((*last_type == COMMAND || *last_type == FILE_PATH
				|| *last_type == LIMITER || *last_type == ARG)
				&& *single_cmd == true)
			current->type = ARG;
	}
	else if (current->type == OP_PIPE)
		*single_cmd = false;
	*last_type = current->type;
}
