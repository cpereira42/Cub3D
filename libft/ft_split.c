/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:28:38 by cpereira          #+#    #+#             */
/*   Updated: 2021/02/17 16:45:04 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count_size(char const *s, char c)
{
	int		tamanho;
	int		controle;
	int		i;

	i = 0;
	tamanho = 0;
	controle = 0;
	while (s[i] != '\0' && s[0] != '\0')
	{
		if (s[i] != c && controle == 0)
		{
			controle = 1;
			tamanho++;
		}
		else if (s[i] == c)
			controle = 0;
		i++;
	}
	return (tamanho);
}

static char	*ret(const char *fr, int inicial, int final)
{
	char	*string;
	int		i;

	i = 0;
	string = (char*)malloc((final - inicial + 1) * sizeof(char));
	while (final > inicial)
	{
		string[i] = fr[inicial];
		i++;
		inicial++;
	}
	string[i] = '\0';
	return (string);
}

char		**ft_split(const char *s, char c)
{
	char	**split;
	int		inicial;
	size_t	i;
	size_t	j;

	if (s == 0)
		return (NULL);
	i = -1;
	j = 0;
	inicial = -1;
	split = malloc((count_size(s, c) + 1) * sizeof(char*));
	if (split == 0)
		return (NULL);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && inicial < 0)
			inicial = i;
		else if ((s[i] == c || i == ft_strlen(s)) && inicial >= 0)
		{
			split[j++] = ret(s, inicial, i);
			inicial = -1;
		}
	}
	split[j] = NULL;
	return (split);
}
