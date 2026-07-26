/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 19:01:56 by jonbezer          #+#    #+#             */
/*   Updated: 2026/05/31 15:13:18 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION
 * The ft_memcmp() function compares byte by byte the first n bytes of the
 * memory areas s1 and s2. Unlike ft_strncmp, this function treats the data 
 * as raw binary memory blocks and does not stop when it encounters a null 
 * character ('\0'). It will strictly scan up to n bytes unless a difference
 * is found.
 *
 * RETURN VALUE
 * Returns an integer less than, equal to, or greater than zero if the first
 * n bytes of s1 are found, respectively, to be less than, to match, or be
 * greater than the first n bytes of s2. The bytes are interpreted as 
 * unsigned characters. If n is 0, the function returns 0.
 */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ps1;
	const unsigned char	*ps2;

	ps1 = (const unsigned char *)s1;
	ps2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*ps1 != *ps2)
			return (*ps1 - *ps2);
		ps1++;
		ps2++;
		n--;
	}
	return (0);
}
/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= 0 && nbr <= 9)
	{
		ft_putchar(nbr + '0');
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

int	main(void)
{
	unsigned int	n;
	char			*st0;
	char			*st1;

	// Note que há um \0 intencional no meio dos blocos de memória
	st0 = "gato\0brabo";
	st1 = "gato\0manso";

	// Teste 1: Comparando os 3 primeiros bytes ("gat") -> Deve dar 0
	n = 3;
	ft_putchar('1');
	ft_putchar(':');
	ft_putchar(' ');
	ft_putnbr(ft_memcmp(st0, st1, n));
	ft_putchar('\n');

	// Teste 2: Comparando 7 bytes (ignora o \0 e acha a diferença 'b' vs 'm')
	n = 7;
	ft_putchar('2');
	ft_putchar(':');
	ft_putchar(' ');
	ft_putnbr(ft_memcmp(st0, st1, n));
	ft_putchar('\n');
}
*/
