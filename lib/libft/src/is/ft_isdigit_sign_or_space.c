/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_sign_or_space.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:26:47 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/27 17:43:13 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if the given char is a sign, number or space
 * @param c The char to check
 * @return 
 * - 1 if the given char is a sign, number or space.
 * 
 * - 0 otherwise
 */
int	ft_isdigit_sign_or_space(int c)
{
	return (c == '+' || c == '-' || ft_isdigit(c) || ft_isspace(c));
}
