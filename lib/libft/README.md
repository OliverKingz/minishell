# **My Personal C Library Libft by ozamora-/oliverkingz**

## **Overview**
This repository contains my personal version of `Libft`, originally based on the 42 curriculum's Libft project. Over time, I have extended and modified it, freeing it from the original project's constraints. It now features additional functions, reorganized folders, and an improved Makefile for better usability and clarity.

## **How to Use**
1. Clone the repository:
	```bash
	git clone https://github.com/oliverkingz/Libft_OZ.git
	cd Libft_OZ
2. Build the library:
	```bash
	make
3. Don't forget to include it in your C files
	```C
	#include "libft.h"

## **Features**
### **Check Functions**
- Utilities to evaluate characters based on type (`ft_isalpha`, `ft_isdigit`, etc.).
- Extended support with added functions like `ft_islower`, `ft_isupper`, and `ft_isspace`.

| Function                   | Description                                        |
| -------------------------- | -------------------------------------------------- |
| [ft_isalpha]               | Checks if the character is alphabetic              |
| [ft_isalnum]               | Checks if the character is alphanumeric            |
| [ft_isascii]               | Checks if the character belongs to ASCII           |
| [ft_isdigit]               | Checks if the character is a digit                 |
| [ft_isprint]               | Checks if the character is printable               |
| **Extra**                  | **Description**                                    |
| [ft_islower]               | Checks if the character is a lowercase letter      |
| [ft_isupper]               | Checks if the character is an uppercase letter     |
| [ft_isspace]               | Checks if the character is a whitespace            |
| [ft_isdigit_sign_or_space] | Checks if the character is a sign, number or space |
| [ft_issigned_nbr]          | Checks if the string is a signed number            |

[ft_isalpha]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/is/ft_isalpha.c
[ft_isalnum]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/is/ft_isalnum.c
[ft_isascii]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/is/ft_isascii.c
[ft_isdigit]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/is/ft_isdigit.c
[ft_isprint]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/is/ft_isprint.c
[ft_islower]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/is/ft_islower.c
[ft_isupper]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/is/ft_isupper.c
[ft_isspace]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/is/ft_isspace.c
[ft_isdigit_sign_or_space]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/is/ft_isdigit_sign_or_space.c
[ft_issigned_nbr]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/is/ft_issigned_nbr.c

### **Conversion Functions**
- Functions to convert strings to various data types: `ft_atoi`, `ft_atol`, `ft_itoa`.
- Functions to convert characters to different cases: `ft_tolower`, `ft_toupper`.

| Function     | Description                                      |
| ------------ | ------------------------------------------------ |
| [ft_atoi]    | Converts a string to an integer                  |
| [ft_itoa]    | Converts an integer to a string                  |
| [ft_tolower] | Converts a character to lowercase                |
| [ft_toupper] | Converts a character to uppercase                |
| **Extra**    | **Description**                                  |
| [ft_atol]    | Converts a string to a long integer              |

[ft_atoi]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/to/ft_atoi.c
[ft_itoa]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/to/ft_itoa.c
[ft_tolower]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/to/ft_tolower.c
[ft_toupper]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/to/ft_toupper.c
[ft_atol]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/to/ft_atol.c

### **String Functions**
- Core functions for handling strings: copying, joining, trimming, and splitting (`ft_strlen`, `ft_strjoin`, `ft_split`).
- Advanced search capabilities (`ft_strchr`, `ft_strrchr`, `ft_strnstr`).
- Functions like `ft_strmapi` and `ft_striteri` enable advanced iteration with user-defined operations.

| Function          | Description                                       |
| ----------------- | ------------------------------------------------- |
| [ft_strlen]       | Calculates the length of a string                 |
| [ft_split]        | Splits a string into an array of strings          |
| [ft_strchr]       | Searches for a character in a string              |
| [ft_strrchr]      | Searches for a character in a string from the end |
| [ft_strnstr]      | Searches for a string within another string       |
| [ft_strdup]       | Duplicates a string                               |
| [ft_striteri]     | Iterates over a string with an index              |
| [ft_strjoin]      | Joins two strings into one                        |
| [ft_strlcat]      | Safely concatenates strings                       |
| [ft_strlcpy]      | Safely copies strings                             |
| [ft_strmapi]      | Iterates over a string and applies a function     |
| [ft_strncmp]      | Compares up to 'n' characters of two strings      |
| [ft_strtrim]      | Trims whitespace from a string                    |
| [ft_substr]       | Extracts a substring                              |
| **Extra**         | **Description**                                   |
| [ft_strrncmp]     | Compares up to 'n' chars of 2 strings from the end|
| [ft_strcmp]       | Compares two strings char by char                 |
| [ft_strjoin_char] | Joins two strings with a char in the middle       |
| [ft_strtok]       | Splits a string into tokens based on delimiters   |

[ft_strlen]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/str/ft_strlen.c
[ft_split]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/str/ft_split.c
[ft_strchr]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/str/ft_strchr.c
[ft_strrchr]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/str/ft_strrchr.c
[ft_strnstr]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/str/ft_strnstr.c
[ft_strdup]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/str/ft_strdup.c
[ft_striteri]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/str/ft_striteri.c
[ft_strjoin]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/str/ft_strjoin.c
[ft_strlcat]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/str/ft_strlcat.c
[ft_strlcpy]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/str/ft_strlcpy.c
[ft_strmapi]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/str/ft_strmapi.c
[ft_strncmp]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/str/ft_strncmp.c
[ft_strtrim]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/str/ft_strtrim.c
[ft_substr]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/str/ft_substr.c
[ft_strrncmp]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/str/ft_strrncmp.c
[ft_strcmp]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/str/ft_strcmp.c
[ft_strjoin_char]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/str/ft_strjoin_char.c
[ft_strtok]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/str/ft_strtok.c

### **Memory Functions**
- Robust tools for memory allocation and manipulation: `ft_calloc`, `ft_memset`, `ft_memmove`.
- Optimized functions for comparisons and scans in memory areas.

| Function      | Description                                  |
| ------------- | -------------------------------------------- |
| [ft_bzero]    | Sets a block of memory to zero               |
| [ft_calloc]   | Allocates memory and initializes it to zero  |
| [ft_memchr]   | Searches for a character in a memory block   |
| [ft_memcmp]   | Compares memory blocks                       |
| [ft_memcpy]   | Copies a memory block                        |
| [ft_memmove]  | Moves a memory block                         |
| [ft_memset]   | Sets a value in a memory block               |

[ft_bzero]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/mem/ft_bzero.c
[ft_calloc]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/mem/ft_calloc.c
[ft_memchr]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/mem/ft_memchr.c
[ft_memcmp]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/mem/ft_memcmp.c
[ft_memcpy]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/mem/ft_memcpy.c
[ft_memmove]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/mem/ft_memmove.c
[ft_memset]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/mem/ft_memset.c

### **Input/Output Functions**
- Write to file descriptors using utilities like `ft_putstr_fd`, `ft_putnbr_fd`.
- Additional output functions from a custom printf implementation: `ft_printf`, `ft_putptr`, `ft_putnbr_base`.

| Function          | Description                                              |
| ----------------- | ---------------------------------------------------------|
| [ft_putchar_fd]   | Writes a character to a file descriptor                  |
| [ft_putendl_fd]   | Writes a line to a file descriptor                       |
| [ft_putnbr_fd]    | Writes a number to a file descriptor                     |
| [ft_putstr_fd]    | Writes a string to a file descriptor                     |
| **Extra**         | **Description**                                          |
| [ft_printf]       | Prints a formatted message                               |
| [ft_putchar]      | Writes a character to the standard output                |
| [ft_putptr]       | Writes a pointer address to a file descriptor            |
| [ft_putstr]       | Writes a string to the standard output                   |
| [ft_putnbr]       | Writes a number to the standard output                   |
| [ft_putnbr_unsigned] | Writes an unsigned number to the standard output      |
| [ft_putnbr_base]  | Writes a number in a specified base to a file descriptor |

[ft_putchar_fd]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/put/ft_putchar_fd.c
[ft_putendl_fd]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/put/ft_putendl_fd.c
[ft_putnbr_fd]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/put/ft_putnbr_fd.c
[ft_putstr_fd]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/put/ft_putstr_fd.c
[ft_printf]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/put/ft_printf.c
[ft_putchar]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/put/ft_putchar.c
[ft_putptr]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/put/ft_putptr.c
[ft_putstr]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/put/ft_putstr.c
[ft_putnbr]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/put/ft_putnbr.c
[ft_putnbr_unsigned]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/put/ft_putnbr_unsigned.c
[ft_putnbr_base]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/put/ft_putnbr_base.c

### **Linked List Operations**
- Manage linked lists easily with node creation, addition, iteration, and mapping (`ft_lstnew`, `ft_lstadd_back`, `ft_lstmap`).

| Function            | Description                                            |
| ------------------- | ------------------------------------------------------ |
| [ft_lstnew]         | Creates a new list node                                |
| [ft_lstadd_front]   | Adds a node to the front of the list                   |
| [ft_lstsize]        | Returns the size of the list                           |
| [ft_lstlast]        | Returns the last node of the list                      |
| [ft_lstadd_back]    | Adds a node to the end of the list                     |
| [ft_lstdelone]      | Deletes a single node                                  |
| [ft_lstclear]       | Deletes and frees the list                             |
| [ft_lstiter]        | Iterates over the list and applies a function          |
| [ft_lstmap]         | Applies a function to each node and creates a new list |

[ft_lstnew]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/lst/ft_lstnew.c
[ft_lstadd_front]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/lst/ft_lstadd_front.c
[ft_lstsize]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/lst/ft_lstsize.c
[ft_lstlast]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/lst/ft_lstlast.c
[ft_lstadd_back]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/lst/ft_lstadd_back.c
[ft_lstdelone]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/lst/ft_lstdelone.c
[ft_lstclear]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/lst/ft_lstclear.c
[ft_lstiter]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/lst/ft_lstiter.c
[ft_lstmap]: https://github.com/oliverkingz/Libft_OZ/blob/main/src/lst/ft_lstmap.c

## **Enhancements**
- **Refined Folder Structure**: Reorganized for a clearer and more modular layout.
- **Improved Makefile**: A polished Makefile that simplifies compilation and provides better options.

## **Skills Learned**
- Proficient use of C to create reusable and maintainable code.
- Handling dynamic memory allocation and management.
- Writing modular and extensible libraries.
- Implementing custom algorithms for string, character, and memory utilities.
- Deep understanding of linked list structures and custom I/O functions.

## **Enhancements**
- **Refined Folder Structure**: Reorganized for a clearer and more modular layout.
- **Improved Makefile**: A polished Makefile that simplifies compilation and provides better options.

## **Skills Learned**
- Proficient use of C to create reusable and maintainable code.
- Handling dynamic memory allocation and management.
- Writing modular and extensible libraries.
- Implementing custom algorithms for string, character, and memory utilities.
- Deep understanding of linked list structures and custom I/O functions.

