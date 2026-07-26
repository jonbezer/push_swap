/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:29:00 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/03 11:21:57 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * SYNOPSIS
 * int ft_toupper(int c);
 *
 * DESCRIPTION
 * The ft_toupper() function converts a lowercase letter to the corresponding 
 * uppercase letter. It evaluates the character value based on the ASCII table:
 * - If c >= 'a' && c <= 'z': Converts the character by subtracting 32 
 * from its value.
 * - If else: Returns the character unchanged.
 *
 * RETURN VALUE
 * If the character is a lowercase letter, the function returns its uppercase 
 * equivalent; otherwise, it returns the original character.
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
