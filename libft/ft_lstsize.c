/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:41:40 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/09 18:40:56 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * SYNOPSIS
 * int ft_lstsize(t_list *lst);
 *
 * DESCRIPTION
 * The ft_lstsize() function counts the number of elements in a linked list.
 * It traverses the list from the beginning to the end, incrementing a
 * counter for each node until the pointer reaches NULL.
 *
 * RETURN VALUE
 * The total number of nodes present in the linked list.
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
