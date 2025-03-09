/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:25:35 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/09 01:31:23 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	validate_rline_syntax(char *read_line)
{
	char	*current;
	int		s_quote_count;
	int		d_quote_count;
	int		i;

	current = read_line;
	s_quote_count = 0;
	d_quote_count = 0;
	i = -1;
	while (current[++i] != '\0')
	{
		if (current[i] == '|' && current[i + 1] == '|') // Consultar Raul
			return (ft_puterr(ERR_SYNTAX), false);
		if (current[i] == '\'')
			s_quote_count++;
		if (current[i] == '\"')
			d_quote_count++;
	}
	if (current[i - 1] == '|' || current[i - 1] == '>' || current[i - 1] == '<')
		return (ft_puterr(ERR_SYNTAX_NL), false);
	if ((s_quote_count % 2) == 1 || (d_quote_count % 2) == 1)
		return (ft_puterr(ERR_SYNTAX), false);
	return (true);
}
