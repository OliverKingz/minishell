/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:12:03 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/24 21:05:44 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief  Sends a string to the specified file descriptor, followed by a \n
 * @param s:  The string to send.
 * @param fd: The file descriptor on which to write.
 * @return Nothing.
 * @note 
 * - The function ensures that a newline character is written to 'fd' after 
 * writing the string 's', effectively appending a newline to the output.
 * 
 * - If the input string 's' is NULL, the function still writes a newline 
 * character to 'fd', maintaining consistent behavior in handling NULL 
 * string inputs.
 */
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (fd < 0)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
