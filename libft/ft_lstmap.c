/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:40:15 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/10 23:40:11 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * SYNOPSIS
 * t_list	ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
 *
 * PARAMETERS
 * lst: A pointer to the first node of the original list.
 * f: The function pointer used to transform the content of each node.
 * del: The function pointer used to free node content if allocation fails.
 *
 * DESCRIPTION
 * Iterates through the linked list 'lst' and applies the function 'f' to 
 * the content of each node. A completely new list is created dynamically 
 * by allocating new nodes with the transformed contents. 
 * If any memory allocation fails during the process, the function cleans 
 * up perfectly, freeing all previously allocated memory (both contents 
 * and nodes) using the 'del' function to prevent memory leaks.
 *
 * RETURN VALUE
 * Returns a pointer to the first node of the brand-new mapped list.
 * Returns NULL if any dynamic allocation fails or if input functions 
 * are invalid.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	new_list = NULL;
	if (!f || !del)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
