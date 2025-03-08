/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:38:21 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/08 16:12:14 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares two strings up to a specified number of characters.
 * @param s1 The first string.
 * @param s2 The second string.
 * @param n The maximum number of characters to compare.
 * @return 
 * - A negative value if 's1' is less than 's2'.
 * 
 * - Zero if 's1' is equal to 's2'.
 * 
 * - A positive value if 's1' is greater than 's2'.
 * @note The comparison stops at the first differing character, at a null byte, 
 * or after 'n' characters have been compared.
 * 
 * - Handles NULL pointers, n overflow, and non-ASCII characters
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && i + 1 < n && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
