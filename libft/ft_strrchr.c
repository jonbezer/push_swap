/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:38:53 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/11 12:55:08 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * SYNOPSIS
 * char *ft_strrchr(const char *s, int c);
 *
 * DESCRIPTION
 * The ft_strrchr() function locates the last occurrence of c (converted to a 
 * char) in the string pointed to by s. 
 * It scans the string using pointer arithmetic:
 * - Advances the pointer s directly through the memory, saving the current 
 *   address in last whenever a match is found.
 * - Evaluates the final NUL terminator directly to safely handle searches 
 *   for the '\0' character.
 *
 * RETURN VALUE
 * The ft_strrchr() function returns a pointer to the last located character, 
 * or NULL if the character does not appear in the string.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (last);
}
