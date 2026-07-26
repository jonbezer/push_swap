/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 00:00:49 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/11 00:43:12 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* DESCRIPTION
* Outputs the integer 'n' to the specified file descriptor 'fd'.
* The function handles negative numbers, zero, and extreme values safely
* by utilizing a long int casting to prevent integer overflow during
* sign inversion (especially for INT_MIN). It employs linear recursion
* to isolate and display each digit from left to right.
*
* PARAMETERS
* n: The integer value to be printed.
* fd: The file descriptor where the output will be directed.
*
* RETURN VALUE
* None.
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar_fd(nb + '0', fd);
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}
