/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:48:15 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/22 15:23:42 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strnstr - Locates a substring in a string with size limit.
 * 
 * @big: The string to search.
 * @little: The substring to locate.
 * @len: The size limit for the search.
 * 
 * Return: Pointer to the first occurrence of 'little' in 'big' 
 *         within 'len' characters, or NULL if 'little' is not found.
 * 
 * Edge cases checked:
 * - Does not explicitly handle NULL 'big' or 'little'. 
 * - Handles empty 'little' (returns 'big').
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0')
	{
		j = 0;
		while (little[j] != '\0' && i + j < len && big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
