/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 17:58:19 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/09 13:44:20 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* SYNOPSIS
 * t_list *ft_lstnew(void *content);
 * 
 * DESCRIPTION
 * Allocates (with malloc) and returns a new node.
 * The member 'content' is initialized with the value of the parameter
 * 'content'. The variable 'next' is initialized to NULL, ensuring the
 * new element is safely isolated.
 *
 * RETURN VALUE
 * A pointer to the newly allocated node. Returns NULL if memory
 * allocation fails.
 */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
