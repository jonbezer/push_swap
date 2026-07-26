/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 23:38:51 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/06 23:44:02 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * SYNOPSIS
 * void	ft_putchar_fd(char c, int fd);
 *
 * DESCRIPTION
 * Outputs the character 'c' to the given file descriptor 'fd'.
 *
 * PARAMETERS
 * c: The character to output.
 * fd: The file descriptor on which to write.
 * 
 * RETURN VALUE
 * None.
 */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
