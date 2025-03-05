/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:52:12 by mzolotar          #+#    #+#             */
/*   Updated: 2025/02/25 10:57:32 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
* @brief 
*
* @param 
* @return 
*/

void toggle_quotes(char c, bool *in_single_quote, bool *in_double_quote)
{
    if (c == '\'')
        *in_single_quote = !(*in_single_quote) && !(*in_double_quote); // Alterna el estado de las comillas simples
    else if (c == '"')
        *in_double_quote = !(*in_double_quote) && !(*in_single_quote); // Alterna el estado de las comillas dobles
}

/**
* @brief 
*
* @param 
* @return 
*/

bool	is_operator(const char *str, const char *op)
{
	return (ft_strncmp(str, op, ft_strlen(op)) == 0);
}

/**
* @brief 
*
* @param 
* @return 
*/

void	update_quote_status(const char c, t_metachars *meta)
{
	toggle_quotes(c, &meta->in_single_quote, &meta->in_double_quote);
}
