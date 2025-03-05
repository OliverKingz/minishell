/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:16:36 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/22 15:24:05 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strtrim - Trims characters from the start and end of a string 's1'
 *              based on the characters in 'set'.
 * 
 * @s1:  The string that needs to be trimmed.
 * @set: The characters to remove from the string.
 * 
 * Return: The trimmed string.
 *         NULL if the memory allocation fails.
 * 
 * Edge cases checked:
 * - Handles empty strings and empty sets.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] != '\0')
	{
		if (ft_strchr(set, s1[start]) != NULL)
			start++;
		else
			break ;
	}
	end = ft_strlen(s1) - 1;
	while (end > start)
	{
		if (ft_strchr(set, s1[end]) != NULL)
			end--;
		else
			break ;
	}
	trimmed = ft_substr(s1, start, (end - start + 1));
	return (trimmed);
}
/** Without using ft_strchr
 * 	start = 0;
	while (s1[start] != '\0')
	{
		i = 0;
		while (s1[start] != set[i] && set[i] != '\0')
			i++;
		if (s1[start] == set[i])
			start++;
		else
			break ;
	}
	end = ft_strlen(s1) - 1;
	while (end > start)
	{
		i = 0;
		while (s1[end] != set[i] && set[i] != '\0')
			i++;
		if (s1[end] == set[i])
			end--;
		else
			break ;
	}
 */