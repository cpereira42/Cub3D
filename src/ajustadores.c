/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ajustadores.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:42:47 by cpereira          #+#    #+#             */
/*   Updated: 2021/02/16 20:03:13 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		convert_rgb(char *cor, t_all *all, char c)
{
	char	**cores;

	cores = ft_split(cor, ',');
	if (cores == 0 || conta_caracter(cor) != 2 || cores[0] == 0
	|| cores[1] == 0 || verifica_numero(cores[0]) ||
	cores[2] == 0 || verifica_numero(cores[1]) || verifica_numero(cores[2]))
	{
		all->erros.msg = "Cor inválida\n";
		free_array((void*)cores);
		return (0);
	}
	all->r = cores[0] != 0 ? ft_atoi(cores[0]) : 0;
	all->g = cores[1] != 0 ? ft_atoi(cores[1]) : 0;
	all->b = cores[2] != 0 ? ft_atoi(cores[2]) : 0;
	limite_cores(all, c);
	free_array((void*)cores);
	return (all->r << 16 | all->g << 8 | all->b);
}

void	limite_cores(t_all *all, char c)
{
	if (all->r > 255 || all->r < 0 || all->g > 255 || all->g < 0
	|| all->b > 255 || all->b < 0)
	{
		if (c == 'F')
			all->erros.f = 2;
		else
			all->erros.c = 2;
	}
}

int		verifica_numero(char *entrada)
{
	size_t t;

	t = 0;
	while (t < ft_strlen(&entrada[t]) || entrada[t] != '\0')
	{
		if (!ft_isdigit(entrada[t]))
			return (1);
		t++;
	}
	return (0);
}

int		verifica_angulo(t_all *all)
{
	char orientacao;

	orientacao = all->fl.orientacao;
	all->controle.meu_x = all->fl.meu_x * 10 + 5;
	all->controle.meu_y = all->fl.meu_y * 10 + 5;
	if (orientacao == 'N')
		return (180);
	if (orientacao == 'S')
		return (0);
	if (orientacao == 'E')
		return (90);
	if (orientacao == 'W')
		return (270);
	return (-1);
}

int		conta_caracter(char *entrada)
{
	int i;
	int qtd;

	qtd = 0;
	i = 0;
	while (entrada[i] != '\0')
	{
		if (entrada[i] == ',')
			qtd++;
		i++;
	}
	return (qtd);
}
