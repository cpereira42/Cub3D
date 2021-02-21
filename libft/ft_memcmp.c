/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:33:01 by cpereira          #+#    #+#             */
/*   Updated: 2020/01/31 19:01:36 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*frase1;
	unsigned char	*frase2;
	unsigned int	i;

	i = 0;
	frase1 = (unsigned char *)s1;
	frase2 = (unsigned char *)s2;
	while (i < n)
	{
		if (frase1[i] != frase2[i])
			return (frase1[i] - frase2[i]);
		i++;
	}
	return (0);
}
