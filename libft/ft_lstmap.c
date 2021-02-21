/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 22:57:27 by cpereira          #+#    #+#             */
/*   Updated: 2020/01/31 19:17:33 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *map;

	if (!lst)
		return (NULL);
	else
	{
		if (!(map = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&map, del);
			return (NULL);
		}
		map->next = ft_lstmap(lst->next, f, del);
		return (map);
	}
}
