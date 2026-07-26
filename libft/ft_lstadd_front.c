/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:35:17 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/09 17:34:13 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* DESCRIPTION
* Adds the element 'new' at the beginning of the list 'lst'. 
* The function updates the head pointer of the list to point directly 
* to the newly added node, ensuring the existing list is preserved and 
* attached right after it.
*
* PARAMETERS
* lst: A pointer to the pointer of the first link of a list.
* new: A pointer to the node to be added at the front of the list.
*
* RETURN VALUE
* None.
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
