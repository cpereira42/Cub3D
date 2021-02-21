/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:22:36 by cpereira          #+#    #+#             */
/*   Updated: 2020/01/30 02:20:43 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t n)
{
	size_t i;
	size_t t_dst;
	size_t t_src;
	size_t soma;

	i = 0;
	t_dst = ft_strlen(dst);
	t_src = ft_strlen(src);
	if (n > t_dst)
		soma = t_dst + t_src;
	else
		soma = n + t_src;
	while (src[i] != '\0' && t_dst < (n - 1) && n > 0)
	{
		dst[t_dst] = src[i];
		i++;
		t_dst++;
	}
	if (t_dst <= n)
		dst[t_dst] = '\0';
	return (soma);
}
