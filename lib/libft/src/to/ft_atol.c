/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:47:08 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/29 16:54:37 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts a string to a long integer.
 * @param nptr: The string to convert.
 * @return The converted long integer.
 * @note
 * - Handles leading whitespace characters (space, newline, tab, vertical tab,
 * form feed, carriage return).
 * 
 * - Supports '+' and '-' signs.
 * 
 * - Stops conversion on the first non-numeric character.
 * 
 * - Does not handle long integer overflow or underflow.
 * 
 * - For applications requiring detection of overflow/underflow or
 *   conversion of strings beyond the range of long, consider using strtol.
 * 
 * - Look at man strtol for full atoi instructions
 */
long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == '\f' || nptr[i] == '\n' || nptr[i] == '\r'
		|| nptr[i] == '\t' || nptr[i] == '\v' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (sign * res);
}
