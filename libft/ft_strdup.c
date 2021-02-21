/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:47:41 by cpereira          #+#    #+#             */
/*   Updated: 2020/01/31 19:04:53 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	t;
	char	*cpy;
	int		i;

	t = ft_strlen(s1) + 1;
	i = 0;
	if ((cpy = (char*)malloc(sizeof(char) * t)))
	{
		while (s1[i] != '\0')
		{
			cpy[i] = s1[i];
			i++;
		}
		cpy[i] = '\0';
		return (cpy);
	}
	else
		return (0);
}
