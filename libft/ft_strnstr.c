/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:47:45 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/01 20:20:40 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * LIBRARY: Libft (BSD standard extension)
 * NAME: ft_strnstr — locate a substring in a string (size-bounded)
 *
 * SYNOPSIS:
 * char *ft_strnstr(const char *haystack, const char *needle, size_t len);
 *
 * DESCRIPTION:
 * The ft_strnstr() function locates the first occurrence of the null-terminated
 * string 'needle' inside the string 'haystack', searching no more than 'len'
 * characters. Characters after a '\0' are completely ignored.
 *
 * RETURN VALUE:
 * - If 'needle' is an empty string, 'haystack' is returned.
 * - If 'needle' occurs nowhere in 'haystack' within 'len' bytes, 
 *   NULL is returned.
 * - Otherwise, it returns a pointer to the specific address where the located
 *   substring begins inside 'haystack'.
 */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && (i + j) < len && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
