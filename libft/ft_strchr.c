/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:38:38 by cpereira          #+#    #+#             */
/*   Updated: 2020/01/23 21:09:15 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*frase;

	frase = (void *)s;
	i = 0;
	while (frase[i] != '\0')
	{
		if (frase[i] == (char)c)
			return (&frase[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&frase[i]);
	else
		return (0);
}
