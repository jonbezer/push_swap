/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 23:44:32 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/06 23:53:24 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * SYNOPSIS
 * void	ft_putstr_fd(char *s, int fd);
 *
 * DESCRIPTION
 * Outputs the string 's' to the given file descriptor 'fd'.
 * If 's' is NULL, the function safe-guards and returns immediately
 * to avoid memory violations.
 *
 * RETURN VALUE
 * None.
 */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
