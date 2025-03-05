/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:11:53 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/24 21:03:03 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a character 'c' to the specified file descriptor 'fd'.
 * @param c:  The character to send.
 * @paramfd: The file descriptor on which to write.
 * @return Nothing.
 * @note 
 * - The caller is responsible for ensuring that 'fd' is a valid file descriptor.
 */
void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
