/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 12:17:14 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/16 09:16:08 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * SYNOPSIS
 * void	*ft_memcpy(void *dst, const void *src, size_t n);
 *
 * DESCRIPTION
 * The ft_memcpy() function copies n bytes from memory area src to
 * memory area dst. The memory areas must not overlap.
 *
 * RETURN VALUE
 * The ft_memcpy() functions returns a pointer to dst.
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;

	if (!dst || !src || !n)
		return (dst);
	pdst = (unsigned char *)dst;
	psrc = (const unsigned char *)src;
	while (n-- > 0)
		*(pdst++) = *(psrc++);
	return (dst);
}
