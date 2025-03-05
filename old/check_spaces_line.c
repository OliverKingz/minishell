/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spaces_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:36:16 by mzolotar          #+#    #+#             */
/*   Updated: 2025/02/25 10:57:24 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
* @brief 
*
* @param 
* @return 
*/

void	copy_operator(char *new_line, t_metachars *meta, const char *line, int op_len)
{
	ft_strlcpy(&new_line[meta->j_new_index], &line[meta->i_current_index],
		op_len + 1);
	meta->j_new_index += op_len;
}

/**
* @brief 
*
* @param 
* @return 
*/

void	process_operators(const char *line, char *new_line, t_metachars *meta)
{
	int	k;
	int	op_len;

	k = 0;
	while (meta->allow_op[k])
	{
		op_len = ft_strlen(meta->allow_op[k]);
		if (is_operator(&line[meta->i_current_index], meta->allow_op[k]))
		{
			if (needs_space_before(line, meta->i_current_index))
				new_line[meta->j_new_index++] = ' ';
			copy_operator(new_line, meta, line, op_len);
			if (needs_space_after(line, meta->i_current_index, op_len))
				new_line[meta->j_new_index++] = ' ';
			meta->i_current_index += op_len - 1;
			return ;
		}
		k++;
	}
	new_line[meta->j_new_index++] = line[meta->i_current_index];
}

/**
* @brief 
*
* @param 
* @return 
*/

void	process_line(const char *line, char *new_line, t_metachars *meta)
{
	meta->i_current_index = 0;
	meta->j_new_index = 0;
	meta->in_single_quote = false;
	meta->in_double_quote = false;
	while (line[meta->i_current_index])
	{
		toggle_quotes(line[meta->i_current_index], &meta->in_single_quote,
			&meta->in_double_quote);
		if (!meta->in_single_quote && !meta->in_double_quote)
			process_operators(line, new_line, meta);
		else
			new_line[meta->j_new_index++] = line[meta->i_current_index];
		meta->i_current_index++;
	}
	new_line[meta->j_new_index] = '\0';
}

/**
* @brief 
*
* @param 
* @return 
*/

void	replace_line(char **line, char *new_line)
{
	char	*temp;

	temp = malloc(ft_strlen(new_line) + 1);
	if (!temp)
	{
		free(new_line);
		printf("malloc failed\n"); // testeo
		return ;
	}
	ft_strlcpy(temp, new_line, ft_strlen(new_line) + 1);
	free(*line);
	*line = temp;
	free(new_line);
}

/**
* @brief 
*
* @param 
* @return 
*/

void	check_spaces_line(char **line, t_metachars *meta)
{
	char	*new_line;

	if (!line || !*line || !meta)
		return ;
	meta->i_current_index = 0;
	meta->j_new_index = 0;
	meta->in_single_quote = false;
	meta->in_double_quote = false;
	new_line = allocate_new_line(*line, meta);
	if (!new_line)
		return ;
	process_line(*line, new_line, meta);
	replace_line(line, new_line);
}
