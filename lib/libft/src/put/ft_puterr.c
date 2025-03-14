/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:23:25 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/14 19:01:41 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Sends a string to the standard error output (stderr).
 * @param s: The string to send.
 * @return Nothing.
 * @note 
 * - The function writes the string 's' to the standard error file descriptor

 * - If the input string 's' is NULL, the function does nothing.
 */
void	ft_puterr(char *s)
{
	if (s == NULL)
		return ;
	write(STDERR_FILENO, s, ft_strlen(s));
}
