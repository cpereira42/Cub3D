/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 00:40:25 by cpereira          #+#    #+#             */
/*   Updated: 2020/02/04 21:03:21 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	tamanho(int n)
{
	int tamanho;

	tamanho = 0;
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		tamanho++;
	}
	return (tamanho);
}

static int	potencia(int tamanho)
{
	int	pot;

	pot = 1;
	while (tamanho > 0)
	{
		pot = pot * 10;
		tamanho--;
	}
	return (pot);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		pot;
	int		i;

	if (!(ret = (char*)malloc((tamanho(n) + 2) * sizeof(char))))
		return (NULL);
	if (n == -2147483648)
		return (ft_substr("-2147483648", 0, 11));
	i = 0;
	if (n < 0)
	{
		ret[i++] = '-';
		n = n * -1;
	}
	pot = potencia(tamanho(n) - 1);
	while (pot > 0)
	{
		ret[i++] = (n / pot % 10 + 48);
		pot = pot / 10;
	}
	ret[i] = '\0';
	return (ret);
}
