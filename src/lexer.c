/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:25:35 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/07 19:36:17 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**tokenize(t_shell *mini_sh, char *read_line)
{
/* 	int		i;
	char	*current;
	char	**tokens;

	current = read_line;
	i = -1;
	while (current && current[i++])
	{
		if (current[i+1])
		{
			if (current[i+1] == '>' && current[i] == '>')
				//create a new substring token containing ">>"
			if (current[i+1] == '>' && current[i] == '>')
				//create a new substring token containung "<<"
		}
		if (current[i] == '<')
			//create a new substring token containing "<"
		if (current[i] == '>')
			//create a new substring token containing ">"
		if (current[i] == '|')
			//create a new substring token containing "|"
		//creates a substrfrom the the initial char until it finds a " "
	}
	return(tokens);
 */
	return (ft_split(read_line, ' '));
}

// void print_tokens(t_token *token_lst)
// {
// 	t_token *current = token_lst;
// 	while (current != NULL)
// 	{
// 		printf("Token Content: %s\n", current->content);
// 		printf("Token Type: %d\n", current->type);
// 		printf("Token Index: %d\n", current->index);
// 		current = current->next;
// 	}
// }