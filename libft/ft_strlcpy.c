/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:07:21 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/11 03:10:49 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * SYNOPSIS
 * size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
 *
 * DESCRIPTION
 * The ft_strlcpy() function copies up to size - 1 characters from the
 * NUL-terminated string src to dst, NUL-terminating the result. It evaluates
 * two memory layout conditions based on buffer sizes:
 * - If srclen + 1 < size: Copies the entire string, including the '\0'
 *   byte, directly from the source using a block memory operation.
 * - If else: Copies size - 1 characters to reserve space and manually
 *   injects the NUL terminator at the last valid index (dst[size - 1] = '\0').
 *
 * RETURN VALUE
 * The ft_strlcpy() function returns the total length of the string it tried
 * to create, which means the length of src.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 <= size)
		ft_memcpy(dst, src, srclen + 1);
	else if (size > 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (srclen);
}
