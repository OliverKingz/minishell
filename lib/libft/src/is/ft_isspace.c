/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:24:58 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/24 17:52:13 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if the given character is a whitespace character.
 * @param c The character to check.
 * @return 
 * - 1 if the character is a whitespace (space, tab, newline, etc.).
 * 
 * - 0 if the character is not a whitespace.
 * @note 
 *  - Evaluates whether the character matches known ASCII whitespace 
 *    characters, including ' ', '\t', '\n', '\v', '\f', '\r'.
 */
int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}
