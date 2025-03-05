/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:38:27 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/22 15:23:45 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strrchr - String reverse search character. 
 * 				Locates the last occurrence of a character in a string.
 * 
 * @s:   The string to be searched.
 * @c:   The character to locate (interpreted as an unsigned char).
 * 
 * Return: A pointer to the last occurrence of the character 'c' in 
 *         the string 's', or NULL if the character is not found.
 * 
 * Description:
 * This function searches for the last occurrence of the character 'c' in the
 * string 's'. If the character is found, a pointer to the position of this 
 * character in the string is returned. If 'c' is not found, the function 
 * returns NULL. The terminating null byte ('\0') is considered part of the 
 * string, so if 'c' is '\0', the function returns a pointer to the terminator.
 */
char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	if (!s)
		return (NULL);
	last = NULL;
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			last = ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return ((char *)last);
}
