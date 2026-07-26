/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 11:53:00 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/04 16:40:51 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* SYNOPSIS
* char	**ft_split(char const *s, char c);
*
* DESCRIPTION
* Allocates (with ft_calloc) and returns an array of strings obtained by
* splitting the string 's' using the character 'c' as a delimiter. 
* The array of pointers is safely terminated by a NULL pointer.
* Memory allocation for each substring is executed dynamically via
* ft_substr. In case of any allocation failure during execution, an 
* internal garbage collector (ft_free) is triggered to release all 
* previously allocated memory blocks, effectively preventing memory leaks.
*
* RETURN VALUE
* The array of new strings resulting from the split.
* NULL if the allocation fails or if 's' is NULL.
*/

#include "libft.h"

static int	ft_cword(char const *s, char c)
{
	int	count;
	int	verify;

	count = 0;
	verify = 0;
	while (*s)
	{
		if (*s != c && verify == 0)
		{
			count++;
			verify = 1;
		}
		else if (*s == c)
			verify = 0;
		s++;
	}
	return (count);
}

static int	ft_wlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

static char	**ft_free(char **split, int i)
{
	while (i > 0)
	{
		i--;
		free(split[i]);
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	char	**split;

	i = 0;
	if (!s)
		return (NULL);
	split = ft_calloc(ft_cword(s, c) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			len = ft_wlen(s, c);
			split[i] = ft_substr(s, 0, len);
			if (!split[i])
				return (ft_free(split, i));
			i++;
			s += len;
		}
	}
	return (split);
}
