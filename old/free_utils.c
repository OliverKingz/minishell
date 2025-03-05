/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:46:03 by mzolotar          #+#    #+#             */
/*   Updated: 2025/03/03 08:59:37 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief 
 *
 * @param 
 * @return 
 */

void	free_split_strs(char **split_strs)
{
	int	i;

	if (!split_strs)
		return ;
	i = 0;
	while (split_strs[i])
	{
		free(split_strs[i]);
		split_strs[i] = NULL;
		i++;
	}
	free(split_strs);
	split_strs = NULL;
}

/**
* @brief 
*
* @param 
* @return 
*/

void	free_tokens_list(t_tokens **tokens)
{
	t_tokens	*temp;
	t_tokens	*current;

	if (tokens == NULL)
		return ;
	current = *tokens;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*tokens = NULL;
}

 /**
* @brief 
*
* @param 
* @return 
*/

void free_meta_struct(t_metachars *meta)
{
	if (!meta)
		return;

	free_split_strs(meta->allow_oper);				//revisar
	free_split_strs(meta->allow_metachar);			//revisar
	free_split_strs(meta->allow_op);				//revisar

	free_split_strs(meta->not_allow_metachar);
	free_split_strs(meta->not_allow_bracket);
	free_split_strs(meta->is_metacharacter);
	
	free_split_strs(meta->not_allow_num_redir);
	free_split_strs(meta->not_allow_other_redir);
	free_split_strs(meta->not_allow_oper);
	free_split_strs(meta->unexpected_token);
	
	//free_split_strs(meta->not_allow_word);
	//free(meta->word);

	free(meta);
}
