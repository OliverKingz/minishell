/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:38:21 by ozamora-          #+#    #+#             */
/*   Updated: 2025/01/18 18:46:43 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strncmp_aux(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

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
	size_t	len1;
	size_t	len2;

	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == NULL && s2 == NULL)
			return (0);
		if (s1 == NULL)
			return (-(unsigned char)s2[0]);
		return ((unsigned char)s1[0]);
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (n == 0)
		return (0);
	if (n > len1)
		n = len1;
	if (n > len2)
		n = len2;
	return (ft_strncmp_aux(s1, s2, n));
}

/*
#include <stdio.h>
int main(void)
{
	char	str[] = "Hello World!";
	char	str_equal[] = "Hello World!";
	char	str_lesser[] = "Hello asdawds";
	char	str_greater[] = "Hello WORLD!!!!!!!!!!!!!!!!";
	int		result;
	unsigned int	n;

	printf("Testing my version of strncmp, that returns:"
	"\n -n if lesser\n  0 if equal \n +n if greater \n\n");
	printf("str =       	%s\n", str);
	printf("str_equal =     %s\n", str_equal);
	printf("str_lesser =    %s\n", str_lesser);
	printf("str_greater =   %s\n\n", str_greater);
	result = ft_strncmp(str, str_equal, sizeof(str) - 1);
	printf("strcmp(str, str_equal, sizeof(str) - 1) =     %d\n", result);
	result = ft_strncmp(str, str_lesser, sizeof(str) - 1);
	printf("strcmp(str, str_lesser, sizeof(str) - 1) =   %d\n", result);
	result = ft_strncmp(str, str_greater, sizeof(str) - 1);
	printf("strcmp(str, str_greater, sizeof(str) - 1) =   %d\n", result);
	
	printf("\nTesting differents n for strncmp:\n");
	n = 0;
	result = ft_strncmp(str, str_equal, n);
	printf("strcmp(str, str_equal, %d) =     %d\n", n, result);
	n = 5;
	result = ft_strncmp(str, str_lesser, n);
	printf("strcmp(str, str_lesser, %d) =   %d\n", n, result);
	n = 50;
	result = ft_strncmp(str, str_greater, n);
	printf("strcmp(str, str_greater, %d) =   %d\n", n, result);
	return (0);
}*/
