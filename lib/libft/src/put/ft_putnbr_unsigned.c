/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 02:46:09 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/24 17:46:37 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes an unsigned integer to the standard output.
 * @param nbr The unsigned integer to print.
 * @return The total number of characters printed.
 * @note 
 * - The function handles unsigned integers and prints them without a sign.
 */
size_t	ft_putnbr_unsigned(unsigned int nbr)
{
	size_t	nbr_len;

	nbr_len = 0;
	if (nbr > 9)
		nbr_len += ft_putnbr_unsigned(nbr / 10);
	nbr_len += ft_putchar((nbr % 10) + '0');
	return (nbr_len);
}
