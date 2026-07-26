/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 10:41:16 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/16 09:34:35 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * SYNOPSIS
 * 	void *ft_memset(void *b, int c, size_t n);
 * DESCRIPTION
 * 	The ft_memset() function fills the first len bytes of the memory area 
 * 	pointed to by b with the constant byte c (converted to an unsigned char).
 * RETURN VALUE
 * 	The ft_memset() function returns a pointer to the memory area b.
*/
#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (n-- > 0)
		*(p++) = (unsigned char)c;
	return (b);
}
