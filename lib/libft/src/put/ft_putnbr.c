/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 02:46:17 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/24 17:46:15 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a signed integer to the standard output.
 * @param nbr The signed integer to print.
 * @return The total number of characters printed.
 * @note 
 *  - Handles negative numbers by printing the '-' sign and recursively 
 *    processes digits using division and modulus.
 */
size_t	ft_putnbr(int nbr)
{
	long	number;
	size_t	nbr_len;

	number = (long)nbr;
	nbr_len = 0;
	if (number < 0)
	{
		nbr_len += ft_putchar('-');
		number = -number;
	}
	if (number > 9)
		nbr_len += ft_putnbr((number / 10));
	nbr_len += ft_putchar((number % 10) + '0');
	return (nbr_len);
}

// Another version
/*
void	ft_putnbr(int number)
{
	int		i;
	char	buffer[10];

	if (number == 0)
		write(1, "0", 1);
	else if (number < 0)
	{
		write(1, "-", 1);
		if (number == -2147483648)
		{
			write(1, "2147483648", 10);
			return ;
		}
		number = -number;
	}
	i = 0;
	while (number > 0)
	{
		buffer[i++] = number % 10 + '0';
		number = number / 10;
	}
	while (i > 0)
		write(1, &buffer[--i], 1);
}
*/
