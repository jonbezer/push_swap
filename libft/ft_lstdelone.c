/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:02:50 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/09 19:20:24 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * SYNOPSIS
 * void	ft_lstdelone(t_list *lst, void (*del)(void*));
 *
 * DESCRIPTION
 * Takes as a parameter a node 'lst' and frees the memory of the node’s
 * content using the function 'del' given as a parameter, then frees the
 * node itself. The memory of 'next' must not be freed under any circumstances.
 *
 * PARAMETERS
 * lst: The node to free.
 * del: The address of the function used to delete the content.
 *
 * RETURN VALUE
 * None.
 */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
}
