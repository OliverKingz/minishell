/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:22:06 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/24 17:34:30 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_printf(const char *format, ...);
static int	check_type_and_print(char c, va_list args);

/**
 * @brief Custom implementation of printf.
 * @param format The format string containing conversion specifiers.
 * @param ... Variadic arguments corresponding to the format specifiers.
 * @return The total number of characters printed.
 * @note Supports conversion specifiers for:
 * `%c` (Characters), 
 * `%s` (Strings), 
 * `%p` (Pointers),
 * `%d`/`%i` (Signed integers),
 * `%u` (Unsigned integers), and 
 * `%x`/`%X` (Hexadecimal numbers).
 */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		print_len;
	int		i;

	va_start(args, format);
	i = 0;
	print_len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			print_len = print_len + check_type_and_print(format[i + 1], args);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		else
			print_len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}

static int	check_type_and_print(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		len += ft_putnbr_base((unsigned int)va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (c == 'X')
		len += ft_putnbr_base((unsigned int)va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

// int	main(void)
// {
// 	int	expected_len;
// 	int	ft_len;
// 	int	og_len;
// 	int	num;

// 	//printf("Testing %% at the end\n");
// 	// ft_len = ft_printf("Test%");
// 	// printf("\n");
// 	// og_len = printf("Test%9");
// 	// printf("\nft_printf length: %d, printf length: %d\n\n", ft_len, og_len);

// 	printf("Testing %%c:\n");
// 	ft_len = ft_printf("ft_printf: Char: %c\n", 'A');
// 	og_len = printf("og_printf: Char: %c\n", 'A');
// 	expected_len = og_len;
// 	printf("Expected length: %d, ft_printf length: %d, printf length: %d\n\n",
// 		expected_len, ft_len, og_len);

// 	printf("Testing %%s:\n");
// 	expected_len = 11;
// 	ft_len = ft_printf("ft_printf: String: %s\n", NULL);
// 	og_len = printf("og_printf: String: %s\n", (char *)NULL);
// 	printf("Expected length: %d, ft_printf length: %d, printf length: %d\n\n",
// 		expected_len, ft_len, og_len);

// 	num = 42;
// 	printf("Testing %%p:\n");
// 	ft_len = ft_printf("ft_printf: Pointer: %p\n", NULL);
// 	og_len = printf("og_printf: Pointer: %p\n", NULL);
// 	printf("ft_printf length: %d, printf length: %d\n\n", ft_len, og_len);

// 	printf("Testing %%d:\n");
// 	ft_len = ft_printf("ft_printf: Decimal: %d\n", 123);
// 	og_len = printf("og_printf: Decimal: %d\n", 123);
// 	expected_len = og_len;
// 	printf("Expected length: %d, ft_printf length: %d, printf length: %d\n\n",
// 		expected_len, ft_len, og_len);

// 	printf("Testing %%i:\n");
// 	ft_len = ft_printf("ft_printf: Integer: %i\n", 456);
// 	og_len = printf("og_printf: Integer: %i\n", 456);
// 	expected_len = og_len;
// 	printf("Expected length: %d, ft_printf length: %d, printf length: %d\n\n",
// 		expected_len, ft_len, og_len);

// 	printf("Testing %%u:\n");
// 	ft_len = ft_printf("ft_printf: Unsigned: %u\n", 12345);
// 	og_len = printf("og_printf: Unsigned: %u\n", 12345);
// 	expected_len = og_len;
// 	printf("Expected length: %d, ft_printf length: %d, printf length: %d\n\n",
// 		expected_len, ft_len, og_len);

// 	printf("Testing %%x:\n");
// 	ft_len = ft_printf("ft_printf: Hex lowercase: %x\n", 42);
// 	og_len = printf("og_printf: Hex lowercase: %x\n", 42);
// 	expected_len = og_len;
// 	printf("Expected length: %d, ft_printf length: %d, printf length: %d\n\n",
// 		expected_len, ft_len, og_len);

// 	printf("Testing %%X:\n");
// 	ft_len = ft_printf("ft_printf: Hex uppercase: %X\n", UINT_MAX);
// 	og_len = printf("og_printf: Hex uppercase: %X\n", UINT_MAX);
// 	expected_len = og_len;
// 	printf("Expected length: %d, ft_printf length: %d, printf length: %d\n\n",
// 		expected_len, ft_len, og_len);

// 	return (0);
// }