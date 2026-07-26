/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 16:43:54 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/05 19:00:00 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* SYNOPSIS
 * char	*ft_itoa(int n);
 * 
 * DESCRIPTION
 * Allocates and returns a string representing the integer received as an
 * argument. It uses a long int type to safeguard against INT_MIN overflow.
 * Memory allocation is performed using ft_calloc(len + 1), which pre-initializes
 * all positions with '\0', ensuring a naturally null-terminated string.
 * The logic extracts individual digits from right to left using modulo 10
 * arithmetic (nb % 10), converts them to their ASCII representation ('0'),
 * and stores them in reverse order within the allocated memory block.
 * Negative signs are stored at index 0 and absolute values are handled cleanly.
 *   
 * RETURN VALUE
 * The string representing the integer. NULL if the allocation fails.
 */

#include "libft.h"

static int	ft_nbrlen(long int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	long int	nb;
	char		*nbr;

	nb = n;
	len = ft_nbrlen(nb);
	nbr = ft_calloc(len + 1, sizeof(char));
	if (!nbr)
		return (NULL);
	if (nb < 0)
	{
		nbr[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		nbr[0] = '0';
	while (nb > 0)
	{
		nbr[len - 1] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	return (nbr);
}
