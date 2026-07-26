/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:35:06 by jonbezer          #+#    #+#             */
/*   Updated: 2026/05/29 15:59:28 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * SYNOPSIS
 * #include "libft.h"
 * int ft_tolower(int c);
 *
 * DESCRIPTION
 * The ft_tolower() function converts an uppercase letter to the corresponding 
 * lowercase letter. It evaluates the character value based on the ASCII table:
 * - If c >= 'A' && c <= 'Z': Converts the character by adding 32 to its value.
 * - If else: Returns the character unchanged.
 *
 * RETURN VALUE
 * If the character is an uppercase letter, the function returns its lowercase 
 * equivalent; otherwise, it returns the original character.
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
