/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:13:35 by mzolotar          #+#    #+#             */
/*   Updated: 2025/03/01 08:43:02 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
* @brief 
*
* @param 
* @return 
*/
//true - own command
//false-sistem command

bool check_own_command(t_tokens *current)
{
	if (ft_strncmp(current->content, "echo", 4) == 0) 
		return (true);
	else if (ft_strncmp(current->content, "cd", 2) == 0) 
		return (true);
	else if(ft_strncmp(current->content, "pwd", 3) == 0)
		return (true);
	else if(ft_strncmp(current->content, "export", 6) == 0)
		return (true);
		else if (ft_strncmp(current->content, "unset", 5) == 0) 
		return (true);
	else if(ft_strncmp(current->content, "env", 3) == 0)
		return (true);
	else if(ft_strncmp(current->content, "exit", 6) == 0)
		return (true);
	return (false);
}

/**
* @brief 
*
* @param 
* @return 
*/

void	assign_redirection_type( t_tokens *current, t_tokens *head)
{
	t_tokens *next_token;
	next_token = ft_find_node_n_position(head, current->position + 1);
	
	current->type = check_redir(current);
	
	if (current->type == redir_l_d)
	{
		if (current->next != NULL && !check_pipe(next_token) && !is_redir(next_token))
        {
            current = current->next;
            current->type = heredoc_delimiter;
        }
	}
	else if (current->type == redir_l_u || current->type == redir_r_u || current->type == redir_r_d)
	{
		if (current->next != NULL && !check_pipe(next_token) && !is_redir(next_token))
        {
            current = current->next;
            current->type = path_name;
        }
	}
}

/**
* @brief 
*
* @param 
* @return 
*/
//true - se asigno untipo 
//false - no se asigno tipo

bool	assign_token_type(t_tokens *current, t_tokens *head)
{
	t_tokens *next_token;
	next_token = ft_find_node_n_position(head, current->position + 1);

	if (check_command(current,head))
	{
		current->type = command;
		if (check_own_command(current))
			current->own_command = true;
	}
	else if (check_argument(current,head))
		current->type = argument;
	else if (check_redir(current) != temp && is_redir(current))
		assign_redirection_type(current,head);
	else if (check_pipe(current))
	{
		current->type = pipe_type;
		if (current->next != NULL && !check_pipe(next_token) && !is_redir(next_token))
        {
            current = current->next;
            current->type = command;
        }
	}
	else
		return (false);
	return (true);
}

/**
* @brief 
*
* @param 
* @return 
*/

void	process_tokens(t_tokens *tokens, bool *has_temp_tokens)
{
	t_tokens	*current;

	current = tokens;
	while (current)
	{
		if (current->type == temp)
		{
			if (assign_token_type(current, tokens))
				*has_temp_tokens = true;
		}
		current = current->next;
	}
}

void	check_type_tokens(t_tokens *tokens)
{
	bool	has_temp_tokens;

	if (!tokens)
		return;
	has_temp_tokens = true;
	while (has_temp_tokens)
	{
		has_temp_tokens = false;
		process_tokens(tokens, &has_temp_tokens);
	}
}

