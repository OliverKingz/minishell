/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type_tokens_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:31:31 by mzolotar          #+#    #+#             */
/*   Updated: 2025/03/01 08:49:58 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
* @brief 
*
* @param 
* @return 
*/
// true = pipe_type
// false no es pipe


bool check_pipe(t_tokens *current)
{
	if (ft_strncmp(current->content, "|", -1) == 0) 
		return (true);
	return (false);
}

/**
* @brief 
*
* @param 
* @return 
*/
// true = redir
// false no es redir

bool is_redir(t_tokens *current)
{
	if (ft_strncmp(current->content, "<", -1) == 0) 
		return (true);
	else if (ft_strncmp(current->content, ">", -1) == 0) 
		return (true);
	else if(ft_strncmp(current->content, ">>", -1) == 0)
		return (true);
	else if(ft_strncmp(current->content, "<<", -1) == 0)
		return (true);
	return (false);
}

/**
* @brief 
*
* @param 
* @return 
*/

t_type check_redir(t_tokens *current)
{
	if(ft_strncmp(current->content, ">>", -1) == 0)
		return (redir_r_d);
	else if(ft_strncmp(current->content, "<<", -1) == 0)
		return (redir_l_d);
	else if (ft_strncmp(current->content, "<", -1) == 0) 
		return (redir_l_u);
	else if (ft_strncmp(current->content, ">", -1) == 0) 
		return (redir_r_u);
	
	return (temp);
}

/**
* @brief 
*
* @param 
* @return 
*/
//true - is command
//false-not command

bool check_command(t_tokens *current, t_tokens *head)
{
	t_tokens *prew_token;
	
	if (current->position == 0)
    {
        if (!is_redir(current) && !check_pipe(current))
            return (true);
        return (false);
    }
	if (current->position > 0)
	{
		prew_token = ft_find_node_n_position(head, current->position-1);
		
		if (check_pipe(prew_token) && !is_redir(current) && !check_pipe(current))
			return (true);
	}
	return (false);	
}

/**
* @brief 
*
* @param 
* @return 
*/
//true - arg
//false - not arg

bool check_argument(t_tokens *current, t_tokens *head)
{
	if (!check_command(current, head) && !check_pipe(current) && !is_redir(current) && current->type != path_name)
		return (true);
	
	return (false);
}