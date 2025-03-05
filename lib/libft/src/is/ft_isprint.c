/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:12:06 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/24 20:25:35 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a character is printable.
 * @c: The character to check.
 * @return 1 if 'c' is printable, 0 otherwise.
 */
int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (16384);
	else
		return (0);
}
