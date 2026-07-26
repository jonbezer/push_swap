/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 18:28:30 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/10 23:57:47 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION
 * The ft_strncmp() function lexicographically compares the two null-terminated
 * strings s1 and s2 character by character. It compares at most n characters.
 * The comparison stops immediately if a difference between characters is found,
 * if a null terminator ('\0') is reached in s1, or if n characters have been
 * successfully compared.
 *
 * RETURN VALUE
 * Returns an integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2. The 
 * comparison is performed using unsigned characters to ensure correct 
 * evaluation * of extended ASCII values. If n is 0, the function returns 0.
 */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
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

	n = 3;
	st0 = "gaTo";
	st1 = "gato";
	ft_putnbr(ft_strncmp(st0, st1, n));
}
*/
