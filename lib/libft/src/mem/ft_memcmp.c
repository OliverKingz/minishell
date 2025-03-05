/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:41:00 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/24 20:39:53 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief  Compares two memory areas.
 * @param s1: The first memory area.
 * @param s2: The second memory area.
 * @param n: Number of bytes to compare.
 * @return Integer less than, equal to, or greater than zero if 
 *         's1' is found, respectively, to be less than, to match, 
 *         or be greater than 's2'.
 * @note 
 * - Stops comparing at 0 or when reaching the limit 'n'.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*mem_s1;
	const unsigned char	*mem_s2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	mem_s1 = (const unsigned char *)s1;
	mem_s2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (mem_s1[i] != mem_s2[i])
			return (mem_s1[i] - mem_s2[i]);
		i++;
	}
	return (0);
}
