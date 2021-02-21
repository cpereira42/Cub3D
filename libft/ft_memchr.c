/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:05:07 by cpereira          #+#    #+#             */
/*   Updated: 2020/01/31 21:29:34 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned int	i;
	char			*frase;

	frase = (void *)s;
	i = 0;
	while (i < n)
	{
		if (frase[i] == (char)c)
			return (&frase[i]);
		i++;
	}
	return (0);
}
