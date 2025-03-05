/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spaces_line_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:52:09 by mzolotar          #+#    #+#             */
/*   Updated: 2025/03/01 13:40:10 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
* @brief 
*
* @param 
* @return 
*/

bool	needs_space_before(const char *line, int i)
{
	return (i > 0 && line[i - 1] != ' ');
}

/**
* @brief 
*
* @param 
* @return 
*/

bool	needs_space_after(const char *line, int i, int op_len)
{
	return (line[i + op_len] != '\0' && line[i + op_len] != ' ');
}

/**
* @brief 
*
* @param 
* @return 
*/

int	count_extra_spaces(const char *line, t_metachars *meta)
{
	int	k;
	int	op_len;
	int	extra_spaces;
	

	extra_spaces = 0;
	k = 0;
	while (meta->allow_op[k])
	{
		op_len = ft_strlen(meta->allow_op[k]);
		if ((is_operator(&line[meta->i_current_index], meta->allow_op[k])))
		{
			if (needs_space_before(line, meta->i_current_index))
				extra_spaces++;
			if (needs_space_after(line, meta->i_current_index, op_len))
				extra_spaces++;
		}
		k++;
	}
	return (extra_spaces);
}

/**
* @brief 
*
* @param 
* @return 
*/

int	count_spaces_for_ops(const char *line, t_metachars *meta)
{
	int	extra_spaces;

	extra_spaces = 0;
	meta->i_current_index = 0;
	meta->in_single_quote = false;
	meta->in_double_quote = false;
	while (line[meta->i_current_index])
	{
		update_quote_status(line[meta->i_current_index], meta);
		if (!meta->in_single_quote && !meta->in_double_quote)
		{
			extra_spaces += count_extra_spaces(line, meta);
		}
		meta->i_current_index++;
	}
	return (extra_spaces);
}

/**
* @brief 
*
* @param 
* @return 
*/

char	*allocate_new_line(const char *line, t_metachars *meta)
{
	int		extra_spaces;
	char	*new_line;

	extra_spaces = count_spaces_for_ops(line, meta);
	if (extra_spaces == 0)
		return (NULL);
	new_line = malloc(ft_strlen(line) + extra_spaces + 1);
	if (!new_line)
	{
		printf("malloc failed"); // testeo
		return (NULL);
	}
	return (new_line);
}