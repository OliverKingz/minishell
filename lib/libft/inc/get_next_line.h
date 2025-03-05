/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:27:13 by ozamora-          #+#    #+#             */
/*   Updated: 2025/01/10 20:13:57 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* ************************************************************************** */

# define MAX_FD 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* ************************************************************************** */
/*
 * Get Next Line Functions:
 * - get_next_line: Reads a line from the file descriptor.
 * - read_and_store: Reads from the fd with a buffer and stores the data.
 * - get_line: gets the line from the buffer stored lines
 * Functions that GNL uses from Libft:
 * - `ft_strdup`
 * - `ft_strchr`
 * - `ft_substr`
 * - `ft_strjoin`
 * - `ft_strlen`
 */
/* ************************************************************************** */

char	*get_next_line(int fd);

/* ************************************************************************** */
#endif