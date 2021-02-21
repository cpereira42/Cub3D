/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:28:41 by cpereira          #+#    #+#             */
/*   Updated: 2021/02/16 07:12:19 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*frase;
	size_t	i;
	size_t	j;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	frase = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char*));
	if (frase == 0)
		return (0);
	j = 0;
	while (s1[i] != '\0')
	{
		frase[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		frase[i] = s2[j];
		j++;
		i++;
	}
	frase[i] = '\0';
	return (frase);
}
