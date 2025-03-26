/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_security.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 01:35:05 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/26 02:23:05 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	security_mark(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			s[i] = -2;
		else if (s[i] == '\"')
			s[i] = -3;
		else if (s[i] == '|')
			s[i] = -4;
		else if (s[i] == '<')
			s[i] = -5;
		else if (s[i] == '>')
			s[i] = -6;
		i++;
	}
}

void	revert_security_mark(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		if (s[i] == -2)
			s[i] = '\'';
		else if (s[i] == -3)
			s[i] = '\"';
		else if (s[i] == -4)
			s[i] = '|';
		else if (s[i] == -5)
			s[i] = '<';
		else if (s[i] == -6)
			s[i] = '>';
		i++;
	}
}
