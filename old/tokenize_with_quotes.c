/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_with_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:42:05 by mzolotar          #+#    #+#             */
/*   Updated: 2025/02/11 08:42:40 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Counts the number of tokens in a string, respecting quotes.
 *
 * @param s The input string to analyze.
 * @return The total number of tokens found in the string.
 */
size_t	ft_count_tokens(const char *s)
{
	size_t	count = 0;
	int		i = 0;
	int		in_quotes = 0;
	char	quote_type = '\0';

	while (s[i])
	{
		if ((s[i] == '"' || s[i] == '\'') && (!in_quotes || quote_type == s[i]))
		{
			if (in_quotes)
				in_quotes = 0;  // Closing quotes
			else
			{
				in_quotes = 1;  // Opening quotes
				quote_type = s[i];
			}
		}
		else if ((s[i] == ' ' || s[i] == '\t') && !in_quotes)
		{
			if (i > 0 && s[i - 1] != ' ' && s[i - 1] != '\t')
				count++;
		}
		i++;
	}
	if (i > 0 && s[i - 1] != ' ' && s[i - 1] != '\t')
		count++;
	return (count);
}

/**
 * @brief Allocates memory for each token in the array based on input string.
 *
 * @param array The array where memory for each token will be allocated.
 * @param s The input string to split into tokens.
 * @return A pointer to the array with allocated memory for each token.
 */

static char	**ft_malloc_tokens(char **array, const char *s)
{
	int	i;
	int	j;
	int	count;
	int		in_quotes;
	char	quote_type;

	i=0;
	j=0;
	count=0;
	in_quotes = 0;
	quote_type = '\0';
	while (s[i])
	{
		if ((s[i] == '"' || s[i] == '\'') && (!in_quotes || quote_type == s[i]))
		{
			if (in_quotes)
			{
				in_quotes = 0;  // Cerrar comillas
				quote_type = '\0';
			}
			else
			{
				in_quotes = 1;  // Abrir comillas
				quote_type = s[i];
			}
		}
		else if ((s[i] == ' ' || s[i] == '\t') && !in_quotes)
		{
			if (count > 0)
			{
				array[j] = malloc(sizeof(char) * (count + 1));
				if (!array[j])
					return (NULL);
				j++;
				count = 0;
			}
		}
		else
		{
			count++;
		}
		i++;
	}
	if (count > 0)
	{
		array[j] = malloc(sizeof(char) * (count + 1));
	}
	return (array);
}


/**
 * @brief Copies the tokens from the input string into the allocated array.
 *
 * @param array The array where tokens will be copied.
 * @param s The input string containing the tokens.
 * @return A pointer to the array with copied tokens.
 */

 static char	**ft_cpy_tokens(char **array, const char *s)
 {
	int	i;
	int	j;
	int x;
	int		in_quotes;
	char	quote_type;

	i=0;
	j=0;
	x=0;
	in_quotes = 0;
	quote_type = '\0';
 
	 while (s[i])
	 {
		 if ((s[i] == '"' || s[i] == '\'') && (!in_quotes || quote_type == s[i]))
		 {
			 if (in_quotes)
			 {
				 in_quotes = 0;  // Cerrar comillas
				 quote_type = '\0';
			 }
			 else
			 {
				 in_quotes = 1;  // Abrir comillas
				 quote_type = s[i];
			 }
		 }
		 else if ((s[i] == ' ' || s[i] == '\t') && !in_quotes)
		 {
			 if (x > 0)
			 {
				 array[j][x] = '\0';
				 j++;
				 x = 0;
			 }
		 }
		 else
		 {
			 array[j][x++] = s[i];
		 }
		 i++;
	 }
	 if (x > 0)
	 {
		 array[j][x] = '\0';
	 }
	 return (array);
 }
 
/**
 * @brief Tokenizes a string while respecting quotes.
 *
 * @param s The input string to tokenize.
 * @return A pointer to an array of tokens or NULL on failure.
 */

char	**tokenize_with_quotes(const char *s)
{
	char	**tokens;
	size_t	num_tokens;

	if (!s)
		return (NULL);
	num_tokens = ft_count_tokens(s);
	tokens = malloc((num_tokens + 1) * sizeof(char *));
	if (!tokens)
		return (NULL);
	if (ft_malloc_tokens(tokens, s))
	{
		ft_cpy_tokens(tokens, s);
		tokens[num_tokens] = NULL;
	}
	else
		free_split_strs(tokens);
	return (tokens);
}