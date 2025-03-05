/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:02:15 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/24 20:55:56 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief  Allocates memory for an array of nmemb members and initializes
 *         it to zero.
 * @param nmemb: Number of elements to allocate.
 * @param size: Size of each element.
 * @return Pointer to the allocated memory, or NULL if allocation fails.
 * @note
 * - Checks for multiplication overflow to prevent undefined behavior.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	total_size;

	if (nmemb == 0 || size == 0)
		return (NULL);
	total_size = nmemb * size;
	if (size != 0 && total_size / size != nmemb)
		return (NULL);
	array = malloc(total_size);
	if (!array)
		return (NULL);
	ft_bzero(array, total_size);
	return (array);
}
