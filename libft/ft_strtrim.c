/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:24:51 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/03 12:32:39 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* SYNOPSIS
* char	*ft_strtrim(char const *s1, char const *set);
*
* DESCRIPTION
* Allocates (with ft_substr) and returns a copy of 's1', with the
* characters specified in 'set' removed from the beginning and the
* end of the string. Characters in the middle of 's1' are completely
* preserved.
*
* RETURN VALUE
* The trimmed string. NULL if the allocation fails or if 's1' or 'set' 
* are missing (NULL pointers).
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	end;
	size_t	start;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	s2 = ft_substr(s1, start, end - start);
	return (s2);
}
