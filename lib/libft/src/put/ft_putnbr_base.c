/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 02:45:58 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/24 20:53:16 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief Writes a number in a specified base to the standard output.
 * @param number The number to print.
 * @param base The base to use for the conversion (e.g., "0123456789ABCDEF").
 * @return The total number of characters printed.
 * @note 
 *  - Converts the number to the specified base and prints it. Handles 
 *    valid base strings and processes digits recursively.
 * 
 * - The base string defines the symbols for digits, with hexadecimal bases
 *   using "0123456789abcdef" or "0123456789ABCDEF".
 */
size_t	ft_putnbr_base(unsigned long number, char *base)
{
	size_t	base_len;
	size_t	nbr_len;
	char	c;

	if (is_valid_base(base) == 0)
		return (0);
	base_len = ft_strlen(base);
	nbr_len = 0;
	if (number >= base_len)
		nbr_len += ft_putnbr_base(number / base_len, base);
	c = base[number % base_len];
	nbr_len += ft_putchar(c);
	return (nbr_len);
}

// size_t	ft_putnbr_base(int nbr, char *base)
// {
// 	long	number;
// 	size_t	base_len;
// 	size_t	nbr_len;
// 	char	c;

// 	if (is_valid_base(base) == 0)
// 		return (0);
// 	base_len = ft_strlen(base);
// 	nbr_len = 0;
// 	number = (long)nbr;
// 	if (number < 0)
// 	{
// 		nbr_len += ft_putchar('-');
// 		number = -number;
// 	}
// 	if (number >= (long) base_len)
// 		nbr_len += ft_putnbr_base(number / base_len, base);
// 	c = base[number % base_len];
// 	nbr_len += ft_putchar(c);
// 	return (nbr_len);
// }

/*
#include <stdio.h>
#include <limits.h> 
int main() {    
    // Test cases for ft_putnbr_base
    ft_putnbr_base(INT_MIN, "0123456789"); printf("\n"); // Expected: -2147483648
    ft_putnbr_base(INT_MIN, "01"); printf("\n"); 
	// Expected: -10000000000000000000000000000000
	ft_putnbr_base(INT_MIN, "0123456789ABCDEF"); printf("\n"); 
	// Expected: -80000000
    ft_putnbr_base(INT_MIN, "01234567"); printf("\n"); // Expected: -20000000000
    ft_putnbr_base(INT_MAX, "0123456789"); printf("\n"); // Expected: 2147483647
    ft_putnbr_base(INT_MAX, "01"); printf("\n"); 
	// Expected: 1111111111111111111111111111111
    ft_putnbr_base(INT_MAX, "0123456789ABCDEF"); printf("\n"); 
	// Expected: 7FFFFFFF
    ft_putnbr_base(INT_MAX, "01234567"); printf("\n"); // Expected: 17777777777
    ft_putnbr_base(0, "0123456789"); printf("\n"); // Expected: 0
    ft_putnbr_base(0, "01"); printf("\n"); // Expected: 0
    ft_putnbr_base(0, "0123456789ABCDEF"); printf("\n"); // Expected: 0
    ft_putnbr_base(0, "01234567"); printf("\n"); // Expected: 0
    ft_putnbr_base(123, "0123456789"); printf("\n"); // Expected: 123
    ft_putnbr_base(123, "01"); printf("\n"); // Expected: 1111011
    ft_putnbr_base(123, "0123456789ABCDEF"); printf("\n"); // Expected: 7B
    ft_putnbr_base(123, "01234567"); printf("\n"); // Expected: 173
    ft_putnbr_base(-456, "0123456789"); printf("\n"); // Expected: -456
    ft_putnbr_base(-456, "01"); printf("\n"); // Expected: -111001000
    ft_putnbr_base(-456, "0123456789ABCDEF"); printf("\n"); // Expected: -1C8
    ft_putnbr_base(-456, "01234567"); printf("\n"); // Expected: -710

    return 0;
}*/