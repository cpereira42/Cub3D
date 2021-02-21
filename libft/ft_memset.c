/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:54:41 by cpereira          #+#    #+#             */
/*   Updated: 2020/01/31 19:03:35 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int letra, size_t tamanho)
{
	size_t			i;
	unsigned char	*frase;

	frase = b;
	i = 0;
	if (tamanho > 0)
	{
		while (i < tamanho)
		{
			frase[i] = letra;
			i++;
		}
	}
	return (frase);
}
