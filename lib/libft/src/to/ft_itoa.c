/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:11:48 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/27 18:38:27 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(unsigned int n_unsigned)
{
	int	counter;

	counter = 1;
	while (n_unsigned >= 10)
	{
		n_unsigned = n_unsigned / 10;
		counter++;
	}
	return (counter);
}

static void	fill_positive_string(char *a, unsigned int n_unsigned, int digits)
{
	int	i;

	i = digits - 1;
	while (n_unsigned > 0)
	{
		a[i] = (n_unsigned % 10) + '0';
		n_unsigned = n_unsigned / 10;
		i--;
	}
}

/**
 * @brief Converts an integer to a string.
 * @n  The integer to be converted.
 * @return 
 * - A pointer to the string representing the integer 'n'.
 * 
 * - Returns NULL if memory allocation fails
 * @warning
 * The string is dynamically allocated and should be freed by the caller
 * @note
 * - The function handles conversion of any integer value, including negative 
 * numbers and zero.
 * 
 * - The resulting string includes a minus sign '-' if the number is negative.
 */
char	*ft_itoa(int n)
{
	unsigned int	n_unsigned;
	char			*a;
	int				digits;

	if (n == INT_MIN)
		n_unsigned = (unsigned int)(INT_MAX) + 1;
	else if (n < 0)
		n_unsigned = (unsigned int)(-n);
	else
		n_unsigned = (unsigned int)n;
	digits = count_digits(n_unsigned) + (n < 0);
	a = (char *)malloc((digits + 1) * sizeof(char));
	if (!a)
		return (NULL);
	if (n < 0)
		a[0] = '-';
	if (n == 0)
		a[0] = '0';
	else
		fill_positive_string(a + (n < 0), n_unsigned, digits - (n < 0));
	a[digits] = '\0';
	return (a);
}
