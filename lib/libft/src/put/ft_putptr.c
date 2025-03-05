/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 02:46:24 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/24 17:45:23 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a pointer address to the standard output in hexadecimal format.
 * @param ptr The pointer to print.
 * @return The total number of characters printed, including `0x` prefix.
 * @warning 
 * The pointer should be valid to avoid undefined behavior.
 * @note 
 *  - Converts the pointer to a hexadecimal representation and prints it,
 *    prefixed with "0x".
 * 
 *  - If the pointer is NULL, it prints "(nil)" and returns the length.
 */
size_t	ft_putptr(void *ptr)
{
	size_t	nbr_len;

	nbr_len = 0;
	if (ptr == NULL)
	{
		nbr_len += ft_putstr("(nil)");
		return (nbr_len);
	}
	nbr_len += ft_putstr("0x");
	nbr_len += ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
	return (nbr_len);
}
