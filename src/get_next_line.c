/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 21:03:54 by cpereira          #+#    #+#             */
/*   Updated: 2021/02/17 14:46:37 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ret_frase(char **frase, char **line)
{
	int		posic;
	char	*aux;

	posic = ft_strpos(*frase, '\n');
	if (posic >= 0)
	{
		*line = ft_substr(*frase, 0, posic);
		aux = ft_substr(*frase, posic + 1, ft_strlen(*frase));
		free(*frase);
		*frase = aux;
		aux = NULL;
		return (1);
	}
	else
		return (0);
}

int	get_next_line(int fd, char **line)
{
	static char		*fr[5000];
	char			buff[1000000];
	ssize_t			ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (fr[fd] != NULL)
	{
		if (ret_frase(&fr[fd], line))
			return (1);
	}
	else
		fr[fd] = ft_strdup("");
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		fr[fd] = (fr[fd] == NULL) ? ft_strdup(buff) : ft_strjoin(fr[fd], buff);
		if (fr[fd] == 0)
			return (-1);
		if (ret_frase(&fr[fd], line))
			return (1);
	}
	*line = ret < 0 ? NULL : fr[fd];
	fr[fd] = NULL;
	return (ret);
}
