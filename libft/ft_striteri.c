/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 14:04:11 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/06 17:40:52 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* SYNOPSIS
* void ft_striteri(char *s, void (*f)(unsigned int, char*));
*
* DESCRIPTION
* Applies the function 'f' on each character of the string passed as argument,
* passing its index as first argument. Each character is passed by address
* to 'f' to be modified if necessary.
*
* RETURN VALUE
* None.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
