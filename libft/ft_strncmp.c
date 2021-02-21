/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:47:33 by cpereira          #+#    #+#             */
/*   Updated: 2020/02/01 00:13:35 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	char		*frase1;
	char		*frase2;

	frase1 = (void *)s1;
	frase2 = (void *)s2;
	i = 0;
	while (i < n)
	{
		if (frase1[i] == '\0' && frase2[i] == '\0')
			return (0);
		if (frase1[i] != frase2[i])
			return ((unsigned char)frase1[i] - (unsigned char)frase2[i]);
		i++;
	}
	return (0);
}
