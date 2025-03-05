/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:12:21 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/22 15:23:16 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_striteri - Applies a function to each character of a string,
 * 					allowing modification.
 *
 * @s: The string to iterate over.
 * @f: The function to apply to each character, which receives the index of
 *     the character and a pointer to the character itself
 *     (allowing modification).
 *
 * Return: Nothing.
 *
 * Notes:
 * - This function allows for the modification of the string 's' in place, as it
 *   passes a pointer to each character to the function 'f'.
 * - The function checks for NULL inputs for both 's' and 'f', and will return
 *   early if either is NULL, ensuring safe operation on valid inputs.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*
void ft_toupper_modified_forIteri(unsigned int x, char *c)
{
	int	i;

	(void)x;
	i = 0;
	while (c[i])
	{
		c[i] = ft_toupper(c[i]);
		i++;
	}
}
int	main(void)
{
	char s[] = "hello";

	printf("Str Original: %s\n", s);
	ft_striteri(s, ft_toupper_modified_forIteri);
	printf("Str (same one) Transformed: %s\n", s);
	return (0);
}
*/
// cc ft_striteri.c ft_toupper.c
