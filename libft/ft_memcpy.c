/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 23:42:03 by cpereira          #+#    #+#             */
/*   Updated: 2020/01/31 19:02:01 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destino, const void *src, size_t tamanho)
{
	unsigned int	i;
	char			*dest;
	const char		*source;

	dest = destino;
	source = (char *)src;
	i = 0;
	while (tamanho > i && destino != src)
	{
		dest[i] = source[i];
		i++;
	}
	return (destino);
}
