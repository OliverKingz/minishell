/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issigned_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:17:19 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/12 21:45:58 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if the given string is a signed number.
 * 
 * This function verifies if the input string represents a valid signed number
 * It skips leading and trailing whitespace characters, checks for an optional
 * sign ('+' or '-'), and ensures that the remaining characters are digits.
 * @param str The string to check
 * @return 
 * - 1 if the string is a signed number.
 * 
 * - 0 if the string is NOT a signed number
 */
int	ft_issigned_nbr(const char *str)
{
	if (str == NULL)
		return (0);
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	while (ft_isspace(*str))
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}
