/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 19:06:59 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/06 16:33:36 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * SYNOPSIS
 * char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
 *
 * DESCRIPTION
 * Applies the function 'f' to each character of the string 's', and passing 
 * its index as first argument to create a new string resulting from successive 
 * applications of 'f'. Memory for the new string is allocated with ft_calloc.
 *
 * RETURN VALUE
 * The string created from the successive applications of 'f'.
 * Returns NULL if the allocation fails or if 's' or 'f' are NULL.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
