/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:12:29 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/22 15:23:34 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strmapi - String map with index.
 * 		Applies a function to each character of a string, creating a new string.
 *
 * @s: The string to iterate over.
 * @f: The function to apply to each character, which receives the character's
 *     index and the character itself.
 *
 * Return:
 *     A new string that is the result of applying 'f' to each character of 's'.
 *     Returns NULL if memory allocation fails or if either 's' or 'f' is NULL.
 *
 * Notes:
 * - The function handles NULL inputs for 's'. If 's' is NULL, the function
 * returns NULL.
 * - The returned string is dynamically allocated and should be freed by
 * the caller.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mapi;
	int				s_len;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	mapi = (char *)malloc((s_len + 1) * sizeof(char));
	if (!mapi)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		mapi[i] = f(i, s[i]);
		i++;
	}
	mapi[i] = '\0';
	return (mapi);
}
/*
char	ft_toupper_modified_forMapi(unsigned int x, char c)
{
	(void)x;
	return ((char)ft_toupper(c));
}

int	main(void)
{
	// 
	char	s[] = "hello";
	char	*s_mapi;

	s_mapi = NULL;
	printf("Str Original:				%s\n", s);
	s_mapi = ft_strmapi(s, ft_toupper_modified_forMapi);
	if (s_mapi)
	{
		printf("Str Mapped (new and different one):	%s\n", s_mapi);
		free(s_mapi);
	}
	return (0);
}
*/
// cc ft_strmapi.c ft_toupper.c ft_strlen.c
