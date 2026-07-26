/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:49:16 by jonbezer          #+#    #+#             */
/*   Updated: 2026/05/28 19:10:25 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * SYNOPSIS
 * void *ft_memmove(void *dst, const void *src, size_t n);
 *
 * DESCRIPTION
 * The ft_memmove() function copies n bytes from memory area src to
 * memory area dst. The memory areas may overlap.
 *
 * RETURN VALUE
 * The ft_memmove() function returns a pointer to the memory area dst.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;

	if (!dst && !src)
		return (0);
	pdst = (unsigned char *)dst;
	psrc = (const unsigned char *)src;
	if (pdst > psrc)
		while (n-- > 0)
			pdst[n] = psrc[n];
	else
		while (n-- > 0)
			*(pdst++) = *(psrc++);
	return (dst);
}
