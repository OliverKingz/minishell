/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:53:53 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/24 15:42:27 by raperez-         ###   ########.fr       */
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
		handle_redir(mini_sh, current, i, &state);
		handle_pipe_space(mini_sh, current, i, &state);
		i[1]++;
	}
	if (i[1] > i[0])
		addback_token(mini_sh, ft_substr(current, i[0], i[1] - i[0]), WORD);
	classify_word_in_tokens(mini_sh);
}

void	classify_word_in_tokens(t_shell *mini_sh)
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
{
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
		{
			current->type = COMMAND;
			*single_cmd = true;
		}
		else if ((*last_type == COMMAND || *last_type == FILE_PATH
				|| *last_type == LIMITER || *last_type == CMD_ARG)
			&& *single_cmd == true)
			current->type = CMD_ARG;
	}
	else if (current->type == OP_PIPE)
		*single_cmd = false;
	*last_type = current->type;
}

void	rm_quotes_in_tokens(t_shell *mini_sh)
{
	t_token	*current;

	current = mini_sh->input->token_lst;
	while (current != NULL)
	{
		mark_variables(current->content, 1);
		rm_external_quotes(current->content);
		current = current->next;
	}
}

void	retokenize(t_shell *mini_sh)
{
	int		i;
	char	**str;
	t_token	*current;

	str = NULL;
	current = mini_sh->input->token_lst;
	while (current != NULL)
	{
		if (current->had_quotes)
		{
			str = ft_split(current->content, ' ');
			my_free((void **)&(current->content));
			current->content = ft_strdup(str[0]);
			i = 1;
			while(str[i])
			{
				insert_token(mini_sh, current, ft_strdup(str[i]), CMD_ARG);
				current = current->next;
				i++;
			}
			my_free2d((void ***) &str);
		}
		current = current->next;
	}
}
