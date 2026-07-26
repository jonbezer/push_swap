/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 22:37:54 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/10 14:05:06 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * SYNOPSIS
 * void	ft_lstiter(t_list *lst, void (*f)(void *));
 * DESCRIPTION
 * Iterates the list 'lst' and applies the function 'f' on the content of
 * each node.
 *
 * PARAMETERS
 * lst: The address of a pointer to a node.
 * f: The address of the function used to iterate on the list.
 *
 * RETURN VALUE
 * None.
 */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
