/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 01:31:43 by mzolotar          #+#    #+#             */
/*   Updated: 2025/02/20 11:34:39 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief 
 *
 * @param 
 * @return 
 */

t_tokens	*find_last_node(t_tokens *tokens)
{
	if (tokens == NULL)
		return (NULL);
	while (tokens->next)
	{
		tokens = tokens->next;
	}
	return (tokens);
}

/**
 * @brief 
 *
 * @param 
 * @return 
 */

static void	initialize_node(t_tokens *tokens, char *content, int position)
{
	if (tokens == NULL)
		return;
	tokens->content = content;
	tokens->type = temp;				
	tokens->own_command = false;
	tokens->expansion = false;			//revisar
	tokens->position = position; 		
	tokens->next = NULL;
}


/**
* @brief 
*
* @param 
* @return 
*/

static void add_node(t_tokens **tokens, char *content, int position)
{
	t_tokens *node;
	t_tokens *last_node;
	
	if (tokens == NULL)
		return ;
	node = malloc(sizeof(t_tokens));
	if (node == NULL)
		return ;
	initialize_node(node, content, position);
	//check_type();
	if (*tokens == NULL)
		*tokens = node;
	else
	{
		last_node = find_last_node(*tokens);
		last_node->next = node;
	}

}

/**
 * @brief 
 *
 * @param 
 * @return 
 */

void init_list(t_tokens **tokens, char **split_str)
{
	int i = 0;
	char *content;
	
	while (split_str[i])
	{
		content = split_str[i];
		add_node(tokens, content, i);  
		++i;
	}
}



 