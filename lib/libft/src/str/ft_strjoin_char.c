/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:52:53 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/03 17:56:32 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates and returns a new string which is the result of the
 * concatenation of 's1', 'c', and 's2'.
 * @param s1 The first string. If NULL, it is treated as an empty string.
 * @param s2 The second string to append to 's1'. If NULL, it is treated as an
 * empty string.
 * @param c The character to insert between 's1' and 's2'.
 * @return A pointer to the newly allocated concatenated string, or NULL if
 * memory allocation fails.
 * @note The function uses malloc, so the caller is responsible for freeing the
 * returned string when it is no longer needed.
 */
char	*ft_strjoin_char(char const *s1, char const *s2, char c)
{
	char	*joined;
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined = (char *)malloc((s1_len + s2_len + 2) * sizeof(char));
	if (!joined)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		joined[i] = s1[i];
	joined[i] = c;
	i++;
	j = -1;
	while (++j < s2_len)
		joined[i + j] = s2[j];
	joined[i + j] = '\0';
	return (joined);
}
