/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 02:03:54 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/26 02:05:45 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_file(char *route)
{
	struct stat	info;

	stat(route, &info);
	return (S_ISREG(info.st_mode));
}

int	is_directory(char *route)
{
	struct stat	info;

	stat(route, &info);
	return (S_ISDIR(info.st_mode));
}
