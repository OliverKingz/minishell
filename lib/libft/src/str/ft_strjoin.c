/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:54:05 by ozamora-          #+#    #+#             */
/*   Updated: 2025/01/09 15:23:52 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates and returns a new string
 * which is the result of the concatenation of 's1' and 's2'.
 * @param s1 The first string. If NULL, it is treated as an empty string.
 * @param s2 The second string to append to 's1'. If NULL, it is treated as an 
 * empty string.
 * @return A pointer to the newly allocated concatenated string, or NULL if 
 * memory allocation fails.
 * @note The function uses malloc, so the caller is responsible for freeing the 
 * returned string when it is no longer needed.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		s1_len;
	int		s2_len;
	int		i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		joined[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		joined[s1_len + i] = s2[i];
		i++;
	}
	joined[s1_len + s2_len] = '\0';
	return (joined);
}
