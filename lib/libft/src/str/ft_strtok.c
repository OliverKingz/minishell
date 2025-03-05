/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:25:09 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/12 21:38:36 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Splits a string into tokens based on delimiters.
 * @param str The string to be tokenized. Pass NULL to continue tokenizing 
 * the previous string.
 * @param delim The delimiters used to split the string.
 * @return A pointer to the next token, or NULL if there are no more tokens.
 */
char	*ft_strtok(char *str, const char *delim)
{
	static char	*last_token = NULL;
	char		*start;

	if (str != NULL)
		last_token = str;
	if (last_token == NULL || *last_token == '\0')
		return (NULL);
	while (*last_token && ft_strchr(delim, *last_token))
		last_token++;
	if (*last_token == '\0')
		return (NULL);
	start = last_token;
	while (*last_token && !ft_strchr(delim, *last_token))
		last_token++;
	if (*last_token != '\0')
	{
		*last_token = '\0';
		last_token++;
	}
	return (start);
}

// int main(void)
// {
// 	char str[] = "Hello, world! This is a test.";
// 	const char *delim = " ,.!";

// 	// Get the first token
// 	char *token = ft_strtok(str, delim);

// 	// Walk through other tokens
// 	while (token != NULL)
// 	{
// 		printf("Token: %s\n", token);
// 		token = ft_strtok(NULL, delim);
// 	}
// 	return 0;
// }