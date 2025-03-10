/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:02:15 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/10 17:49:26 by ozamora-         ###   ########.fr       */
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
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}

// int	main()
// {
// 	char	*ft;
// 	char	*og;
// 	char	*au;

// 	ft = ft_calloc(0, sizeof(char *));
// 	og = calloc(0, sizeof(char *));
// 	au = malloc(0);
// 	printf("ft: %p\t%s\t%lu\n", ft, ft, sizeof(ft));
// 	printf("og: %p\t%s\t%lu\n", og, og, sizeof(og));
// 	printf("au: %p\t%s\t%lu\n", au, au, sizeof(au));
// 	if (!og)
// 		perror("og"), exit(EXIT_FAILURE);
// 	if (!ft)
// 		perror("ft"), exit(EXIT_FAILURE);
// 	if (!au)
// 		perror("au"), exit(EXIT_FAILURE);
// 	free(og);
// 	free(ft);
// 	free(au);
// 	return 0;
// }
