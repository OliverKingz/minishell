/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:39:09 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/24 17:36:56 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a single character to the standard output.
 * @param c The character to write.
 * @return The number of characters printed (always 1).
 */
size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
