/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:08:20 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/22 15:23:26 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strlcpy - Copies a string up to a specified size.
 * 
 * @dst:  The destination buffer where the string will be copied.
 * @src:  The source string to copy from.
 * @size: The size of the destination buffer.
 * 
 * Return: The total length of the string it tried to copy (the length of 'src').
 * 
 * Description:
 * - It copies up to 'size - 1' characters from the source string 'src'
 * to the destination buffer 'dst',
 * - Function ensures the destination string is null-terminated. 
 * - If 'size' is 0, no characters are copied, and only the length of 
 *  'src' is returned.
 * - Function always returns the total length of 'src', regardless of whether
 * the entire string was copied. This can be useful for truncating strings or 
 * determining the necessary buffer size.
 * 
 * Note: The destination buffer must be large enough to receive the string, 
 *       otherwise the string will be truncated.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
// #include <stdio.h>
// int main(void)
// {
// 	size_t	src_size;
// 	size_t	dst_size = 5;
// 	char	*src;
// 	char	dest[dst_size];

// 	src = "Hello world! :3";
// 	src_size = ft_strlcpy(dest, src, sizeof(dest));
// 	printf("Original string with origin_size %d: \n'%s'\n",(int)src_size, src);
// 	printf("Destination string copied from origin "
// 		"with destination_size %d: \n'%s'\n", (int)sizeof(dest), dest); 
// }