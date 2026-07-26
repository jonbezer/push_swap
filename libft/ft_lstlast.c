/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:11:57 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/09 18:40:30 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * SYNOPSIS
 * t_list	*ft_lstlast(t_list *lst);
 * DESCRIPTION
 * * Iterates through the linked list 'lst' to find its final element.
 * The function advances from node to node using the 'next' pointer
 * until it encounters a node where 'next' is NULL, signifying the
 * end of the list.
 *
 * RETURN VALUE
 * Returns a pointer to the last node of the list. If the list is
 * empty (lst is NULL), the function safely returns NULL.
*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
