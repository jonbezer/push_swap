/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:52:25 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/02 22:23:22 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* SYNOPSIS
* char	*ft_substr(char const *s, unsigned in start, size_t len)
*
* DESCRIPTION
* Allocates (with malloc(3)) and returns a substring from the string 's'.
* The substring begins at index 'start' and is of maximum size 'len'.
* If 'start' is greater than the total length of 's', the function returns
* a dynamically allocated empty string ("") to ensure safe freeing.
* If 'len' is larger than the remaining characters from 'start' onwards, 
* 'len' is automatically truncated to match the exact remaining size,
* preventing memory leaks and allocation overflows.
*
* RETURN VALUE
* The new allocated substring; NULL if the memory allocation fails.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	unsigned int	slen;

	slen = ft_strlen(s);
	if (slen < start)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	d = ft_calloc(len + 1, sizeof(char));
	if (!d)
		return (NULL);
	ft_strlcpy(d, s + start, len + 1);
	return (d);
}
