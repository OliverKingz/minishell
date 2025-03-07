/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:39:05 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/07 16:45:01 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a pointer address to the standard output.
 * @param ptr The pointer to print.
 * @return The total number of characters printed.
 * @warning 
 * The string should be null-terminated to avoid unexpected behavior.
 * @note 
 * - Iterates through the string and writes each character until a 
 *    null terminator is encountered.
 * 
 * - If the string is NULL, it prints "(null)" and returns the length.
 */
size_t	ft_putstr(char *str)
{
	size_t	str_len;

	if (str == NULL)
	{
		write(STDOUT_FILENO, "(null)", 6);
		return (6);
	}
	str_len = ft_strlen(str);
	write(STDOUT_FILENO, str, str_len);
	return (str_len);
}
