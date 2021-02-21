/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:13:12 by cpereira          #+#    #+#             */
/*   Updated: 2020/01/31 19:03:13 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t tamanho)
{
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (unsigned char*)src;
	if (dest < source)
		return (ft_memcpy(dst, src, tamanho));
	else
		while (dst != src && tamanho--)
			dest[tamanho] = source[tamanho];
	return (dst);
}
