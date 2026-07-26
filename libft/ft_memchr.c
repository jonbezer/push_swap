/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:03:27 by jonbezer          #+#    #+#             */
/*   Updated: 2026/05/30 18:57:35 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * SYNOPSIS
 * #include "libft.h"
 * void	*ft_memchr(const void *s, int c, size_t n);
 *
 * DESCRIPTION
 * The ft_memchr() function scans the initial n bytes of the memory
 * area pointed to by s for the first instance of c. Both c and the
 * bytes of the memory area pointed to by s are interpreted as
 * unsigned char.
 *
 * RETURN VALUE
 * The ft_memchr() function returns a pointer to the matching byte
 * or NULL (0) if the character does not occur in the given memory area.
 */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;

	ps = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*ps == (unsigned char)c)
			return (ps);
		ps++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*ptr;
	char	*str;

	str = "42 Cursus - Libft";
	ptr = ft_memchr(str, 'i', 14);
	if (ptr == 0)
		return (0);
	else
	{
		printf("%p\n", ptr);
		printf("%c\n", *ptr);
	}
	return (0);
}
*/
