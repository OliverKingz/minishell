/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:28:46 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/12 21:32:05 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* ************************************************************************** */

# include <unistd.h> // To use system calls like write, open, read, close.
# include <fcntl.h>  // To use file control options and constants like O_RDONLY

# include <stdlib.h> // To use memory allocation (malloc, free) and size_t.
# include <stdarg.h> // To use va_list, va_start, va_copy, va_arg and va_end
# include <stdio.h>  // To use printf for testing

# include <stddef.h> // To use NULL and size_t definitions
# include <stdint.h> // To use definitions, to check size_t overflows
# include <limits.h> // To use definitions, to check int overflows
# include <stdbool.h>// To use definitions

# include "get_next_line.h"

/* ************************************************************************** */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* ************************************************************************** */
/*
 * Character Check Functions:
 * - ft_isalpha: Checks if the character is alphabetic.
 * - ft_isdigit: Checks if the character is a digit.
 * - ft_isalnum: Checks if the character is alphanumeric.
 * - ft_isascii: Checks if the character is an ASCII character.
 * - ft_isprint: Checks if the character is printable.
 * Added later:
 * - ft_islower: Checks if the character is lowercase letter.
 * - ft_isupper: Checks if the character is uppercase letter.
 * - ft_isspace: Checks if the character is whitespace.
 * - ft_issigned_nbr: Checks if the string is a signed number 
 * - ft_isdigit_sign_or_space: Checks if the char is a sign, number or space
 */

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

int		ft_islower(int c);
int		ft_isupper(int c);
int		ft_isspace(int c);
int		ft_isdigit_sign_or_space(int c);
int		ft_issigned_nbr(const char *str);

/*
 * Conversion Functions:
 * - ft_tolower: Converts a character to lowercase.
 * - ft_toupper: Converts a character to uppercase.
 * - ft_atoi: Converts a string to an integer.
 * - ft_itoa: Converts an integer to a string.
 * Added later:
 * - ft_atol: Converts a string to a long integer.
 * Planned to add:
 * - ft_strtol: 
 */

int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);

long	ft_atol(const char *nptr);

/*
 * String Functions:
 * - ft_strlen: Returns the length of a string.
 * - ft_strlcpy: Copies a string with a size limit.
 * - ft_strlcat: Appends one string to another with size limit.
 * - ft_strchr: Finds the first occurrence of a character in a string.
 * - ft_strrchr: Finds the last occurrence of a character in a string.
 * - ft_strncmp: Compares up to 'n' characters of two strings.
 * - ft_strnstr: Locates a substring within a string.
 * - ft_substr: Creates a substring from a string.
 * - ft_strjoin: Joins two strings into a new one.
 * - ft_strtrim: Trims characters from both ends of a string.
 * - ft_strdup: Duplicates a string.
 * - ft_split: Splits a string by a delimiter into an array.
 * - ft_strmapi: Applies a function to each character of a string.
 * - ft_striteri: Iterates a string and applies a function to each character.
 * Added later:
 * - ft_strcmp: Compares two strings.
 * - ft_strrncmp: Compares up to n-chars of two strings, starting from the back
 * - ft_strjoin_char: Joins two strings with a char in the middle
 * - ft_strtok: Splits a string into tokens based on delimiters.
 */

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);

char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strdup(const char *s);
char	*ft_strtrim(char const *s1, char const *set);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strrncmp(const char *s1, const char *s2, size_t n);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_char(char const *s1, char const *s2, char c);

char	**ft_split(char const *s, char c);
char	*ft_strtok(char *str, const char *delim);

/*
 * Memory Management Functions:
 * - ft_calloc: Allocates memory for an array and initializes it to zero.
 * - ft_bzero: Zeros out memory.
 * - ft_memset: Fills memory with a constant byte.
 * - ft_memcpy: Copies memory from source to destination.
 * - ft_memmove: Safely copies memory areas that may overlap.
 * - ft_memchr: Scans memory for a byte.
 * - ft_memcmp: Compares two memory areas.
 */

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n); //TOP
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*
 * Output Functions:
 * - ft_putchar_fd: Outputs a character to a file descriptor.
 * - ft_putstr_fd: Outputs a string to a file descriptor.
 * - ft_putendl_fd: Outputs a string to a file descriptor followed by a newline.
 * - ft_putnbr_fd: Outputs an integer to a file descriptor.
 * Added from printf project: 
 * - ft_printf: Custom implementation of printf to print various types.
 * - ft_putchar: Outputs a character to the standard output.
 * - ft_putstr: Outputs a string to the standard output.
 * - ft_putptr: Outputs a pointer address to the standard output.
 * - ft_putnbr: Outputs an integer to the standard output.
 * - ft_putnbr_unsigned: Outputs an unsigned integer to the standard output.
 * - ft_putnbr_base: Outputs a number in a specific base (hexadecimal, etc.).
 */

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

int		ft_printf(const char *format, ...);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *str);
size_t	ft_putptr(void *ptr);
size_t	ft_putnbr(int nbr);
size_t	ft_putnbr_unsigned(unsigned int nbr);
size_t	ft_putnbr_base(unsigned long number, char *base);

/*
 * Linked List Functions:
 * - ft_lstnew: Creates a new node.
 * - ft_lstadd_front: Adds a node to the front of the list.
 * - ft_lstsize: Returns the number of nodes in the list.
 * - ft_lstlast: Returns the last node of the list.
 * - ft_lstadd_back: Adds a node to the end of the list.
 * - ft_lstdelone: Deletes a single node using the provided delete function.
 * - ft_lstclear: Deletes and frees all nodes in the list.
 * - ft_lstiter: Applies a function to each node's content.
 * - ft_lstmap: Creates a new list by applying a function to each node.
 */

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ************************************************************************** */
#endif
