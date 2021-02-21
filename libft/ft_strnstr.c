/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:06:54 by cpereira          #+#    #+#             */
/*   Updated: 2020/02/01 21:14:23 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*palheiro;
	char	*agulha;

	palheiro = (char *)haystack;
	agulha = (char *)needle;
	i = 0;
	if (ft_strlen(agulha) == 0)
		return (&palheiro[0]);
	while (i != len && palheiro[i] != '\0')
	{
		j = 0;
		while (palheiro[i + j] == agulha[j] &&
				agulha[j] != '\0' && (i + j) != len)
			j++;
		if (agulha[j] == '\0')
			return ((char *)&palheiro[i]);
		i++;
	}
	return (0);
}
