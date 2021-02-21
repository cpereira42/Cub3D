/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:41:03 by cpereira          #+#    #+#             */
/*   Updated: 2021/02/14 20:39:59 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	renderiza4(t_all *all)
{
	int		x;
	int		parede;

	x = 1;
	while (x <= all->fl.tela_weight - 1)
	{
		parede = all->distancia.parede[x];
		inicio(all, parede, x);
		all->extras.distx = fmod((all->distancia.ultimo_x[x]
		+ all->controle.meu_x), 10);
		all->extras.disty = fmod((all->distancia.ultimo_y[x]
		+ all->controle.meu_y), 10);
		acao(all, parede, x, 0);
		x++;
	}
}

void	inicio(t_all *all, int parede, int x)
{
	if (parede == 1 || parede == 4)
		all->extras.inicio_x = all->textura[parede].s_width
		* all->extras.disty / 10;
	else
		all->extras.inicio_x = all->textura[parede].s_width
		* all->extras.distx / 10;
	if (all->renderiza[x].tam_parede < all->fl.tela_height)
		all->extras.inicio_y = 0;
	else
		all->extras.inicio_y = (all->renderiza[x].tam_parede
		- all->fl.tela_height) / 2;
}

void	acao(t_all *all, int parede, int x, int z)
{
	float	f;
	float	fator_y;
	int		cor;

	f = all->textura[parede].s_width / (float)all->renderiza[x].tam_parede - 1;
	fator_y = all->textura[parede].s_height /
	(float)all->renderiza[x].tam_parede;
	while (z <= all->fl.tela_height - 1)
	{
		if (z <= all->renderiza[x].limite_superior)
			cor = all->fl.ceil;
		else
		{
			if (z <= all->renderiza[x].limite_inferior)
			{
				cor = get_imagepixel(&all->textura[parede], all->extras.inicio_x
				+ 1 * f, all->extras.inicio_y * fator_y);
				all->extras.inicio_y++;
			}
			else
				cor = all->fl.floor;
		}
		my_mlx_pixel_put(&all->mlx.janela, x, z, cor);
		z += 1;
	}
}

double	corrige_angulo(double entrada)
{
	if (entrada > 33)
		return (entrada - 360);
	if (entrada < -33)
		return (entrada + 360);
	return (entrada);
}

void	tamanho_bloco(t_all *all)
{
	int x;
	int y;

	all->controle.tamanho_min_x = 300;
	all->controle.tamanho_min_y = 300;
	all->controle.tamanho_borda = 8;
	all->controle.minimapa_x = -1;
	x = all->controle.tamanho_min_x / all->fl.tamanho_mapa_x;
	y = all->controle.tamanho_min_y / all->fl.tamanho_mapa_y;
	all->controle.tamanho_bloco = x > y ? y : x;
}
