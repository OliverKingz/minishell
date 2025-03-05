/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:38:03 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/22 15:23:23 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strlcat - Concatenates strings with size limit.
 * 
 * @dst: Destination string.
 * @src: Source string.
 * @size: Size of the destination buffer.
 * 
 * Return: Total length of the string attempted to create.
 * 
 * Edge cases checked:
 * - Handles NULL pointers and size of 0.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	while (dst[dst_len] != '\0' && dst_len < size)
		dst_len++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size <= dst_len)
		return (src_len + size);
	i = 0;
	while (src[i] != '\0' && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
#include <stdio.h>
#include <string.h>

int main(void) {
	char dest[20];
	char src[] = "_world!";
	size_t combined_size;

	strcpy(dest, "Hello");
	printf("Case 1: Normal concatenation\n");
	printf("Before: dest=\"%s\", src=\"%s\"\n", dest, src);
	combined_size = ft_strlcat(dest, src, sizeof(dest));
	printf("After: dest=\"%s\", size=%u\n\n", dest, (unsigned int)combined_size);

	strcpy(dest, "Hello");
	printf("Case 2: Size is 0\n");
	printf("Before: dest=\"%s\", src=\"%s\"\n", dest, src);
	combined_size = ft_strlcat(dest, src, 0);
	printf("After: dest=\"%s\", size=%u\n\n", dest, (unsigned int)combined_size);

	strcpy(dest, "Hello");
	printf("Case 3: Size < length of dest\n");
	printf("Before: dest=\"%s\", src=\"%s\"\n", dest, src);
	combined_size = ft_strlcat(dest, src, 3);
	printf("After: dest=\"%s\", size=%u\n\n", dest, (unsigned int)combined_size);

	strcpy(dest, "Hello");
	printf("Case 4: Size > length of dest but < combined length\n");
	printf("Before: dest=\"%s\", src=\"%s\"\n", dest, src);
	combined_size = ft_strlcat(dest, src, 10);
	printf("After: dest=\"%s\", size=%u\n\n", dest, (unsigned int)combined_size);

	strcpy(dest, "");
	printf("Case 5: dest is empty\n");
	printf("Before: dest=\"%s\", src=\"%s\"\n", dest, src);
	combined_size = ft_strlcat(dest, src, sizeof(dest));
	printf("After: dest=\"%s\", size=%u\n\n", dest, (unsigned int)combined_size);

	strcpy(dest, "Hello");
	src[0] = '\0';
	printf("Case 6: src is empty\n");
	printf("Before: dest=\"%s\", src=\"%s\"\n", dest, src);
	combined_size = ft_strlcat(dest, src, sizeof(dest));
	printf("After: dest=\"%s\", size=%u\n\n", dest, (unsigned int)combined_size);

	strcpy(dest, "Hello");
	strcpy(src, "World");
	printf("Case 7: size = length of dest\n");
	printf("Before: dest=\"%s\", src=\"%s\"\n", dest, src);
	combined_size = ft_strlcat(dest, src, 5);
	printf("After: dest=\"%s\", size=%u\n\n", dest, (unsigned int)combined_size);

	strcpy(dest, "");
	strcpy(src, "");
	printf("Case 8: dest and src are empty\n");
	printf("Before: dest=\"%s\", src=\"%s\"\n", dest, src);
	combined_size = ft_strlcat(dest, src, sizeof(dest));
	printf("After: dest=\"%s\", size=%u\n\n", dest, (unsigned int)combined_size);

	return 0;
}*/