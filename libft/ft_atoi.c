/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:14:36 by cpereira          #+#    #+#             */
/*   Updated: 2020/01/28 18:24:18 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	const char		*frase;
	int				total;
	unsigned int	i;
	int				mult;

	frase = (const char *)str;
	i = 0;
	total = 0;
	mult = 1;
	if (ft_strlen(frase) == 0)
		return (0);
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (frase[i] == '-')
		mult = -1;
	if (frase[i] == '-' || frase[i] == '+')
		i++;
	while (ft_isdigit(frase[i]))
	{
		total = total * 10 + frase[i] - 48;
		i++;
	}
	return (total * mult);
}
