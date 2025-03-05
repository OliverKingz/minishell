/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:12:08 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/24 21:02:44 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Sends an integer to the specified file descriptor.
 * @param n:  The number to send.
 * @param fd: The file descriptor on which to write.
 * @return: Nothing.
 * @note 
 * - Handles the integer minimum value (INT_MIN) correctly by manually managing
 *   overflow and ensuring the last digit is accurately represented.
 */
void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == INT_MIN)
		{
			ft_putnbr_fd(-(n / 10), fd);
			ft_putchar_fd('8', fd);
			return ;
		}
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd((n / 10), fd);
	ft_putchar_fd((n % 10) + '0', fd);
}
