/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:18:34 by ozamora-          #+#    #+#             */
/*   Updated: 2025/01/09 15:13:44 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Duplicates a given string.
 * @param s The string to duplicate.
 * @return A pointer to the newly allocated copy of the string, or NULL if
 * memory allocation fails.
 * @note The caller is responsible for freeing the returned string.
 * Does not handle NULL input, to replicate the origina function.
 */
char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	dup = (char *)malloc((s_len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, s_len + 1);
	return (dup);
}
