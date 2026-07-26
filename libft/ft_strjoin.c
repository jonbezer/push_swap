/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:42:49 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/03 11:17:28 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* SYNOPSIS
* char	*ft_strjoin(char const *s1, char const *s2);
*
* DESCRIPTION
* Allocates (with ft_calloc) and returns a new string, which is the result 
* of the concatenation of 's1' and 's2'.
*
* RETURN VALUE
* The new string. NULL if the allocation fails or if input strings are missing.
*/

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	strlen;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	strlen = ft_strlen(s1) + ft_strlen(s2);
	s3 = ft_calloc(strlen + 1, sizeof(char));
	if (!s3)
		return (NULL);
	ft_strlcat(s3, s1, strlen + 1);
	ft_strlcat(s3, s2, strlen + 1);
	return (s3);
}
