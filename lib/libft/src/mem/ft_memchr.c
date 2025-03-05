/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:41:02 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/24 20:40:46 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief  Locates the first occurrence of a byte in a memory area.
 * @param s: Pointer to the memory area.
 * @param c: The byte to locate.
 * @param n: Number of bytes to examine.
 * @return Pointer to the first occurrence of 'c' in 's', or NULL 
 *         if 'c' is not found within the first 'n' bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			break ;
		i++;
	}
	if (i < n)
		return (((unsigned char *)s) + i);
	else
		return (NULL);
}
