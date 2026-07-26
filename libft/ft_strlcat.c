/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 11:31:13 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/11 03:15:58 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * SYNOPSIS
 * size_t ft_strlcat(char *dst, const char *src, size_t size);
 *
 * DESCRIPTION
 * The ft_strlcat() function appends the NUL-terminated string src to the end 
 * of dst. It evaluates two memory layout conditions based on buffer sizes:
 * - If size <= dlen: No concatenation occurs because the buffer is already 
 *   full or restricted; returns size + slen.
 * - If else: Appends characters from src to dst starting at index dlen, 
 *   stopping before size - 1 to manually guarantee NUL-termination.
 *
 * RETURN VALUE
 * The ft_strlcat() function returns the total length of the string it tried 
 * to create, which means the initial length of dst plus the length of src.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	i = 0;
	dlen = 0;
	slen = 0;
	while (dst[dlen] && dlen < size)
		dlen++;
	while (src[slen])
		slen++;
	if (size <= dlen)
		return (size + slen);
	while (src[i] && (dlen + i) < (size - 1))
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
