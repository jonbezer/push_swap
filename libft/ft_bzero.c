/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 11:40:32 by jonbezer          #+#    #+#             */
/*   Updated: 2026/05/27 12:07:20 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* 
* DESCRIPTION
* The ft_bzero() function erases the data in the n bytes of the memory
* starting at the location pointed to by s, by writing zeros (bytes
* containing '\0') to that area.
* This implementation promotes code modularity by reusing the previously
* tested ft_memset() function, passing 0 as the specific character 
* value to clear the memory area safely and efficiently.
*
* PARAMETERS
* s:  A generic pointer to the initial memory block to be zeroed out.
* n:  The total number of consecutive bytes to be overwritten with zeros.
*
* RETURN VALUE
* None.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
