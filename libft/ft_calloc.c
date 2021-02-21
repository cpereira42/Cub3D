/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:02:38 by cpereira          #+#    #+#             */
/*   Updated: 2020/01/31 18:59:52 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	i;
	size_t	len;

	mem = malloc(count * size);
	if (mem == 0)
		return (NULL);
	i = 0;
	len = count * size;
	while (len > 0)
	{
		((char*)mem)[i] = '\0';
		i++;
		len--;
	}
	return (mem);
}
