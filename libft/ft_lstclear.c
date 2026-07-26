/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:23:07 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/09 19:32:39 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* SYNOPSIS
 * void	ft_lstclear(t_list **lst, void (*del)(void*));
 *
 * DESCRIPTION
 * Deletes and frees the given node and all its successors, using the
 * function 'del' and free(3). Finally, the pointer to the list is
 * set to NULL.
 *
 * PARAMETERS
 * lst: The address of a pointer to a node.
 * del: The address of the function used to delete the content of the node.
 *
 * RETURN VALUE
 * None.
 */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
