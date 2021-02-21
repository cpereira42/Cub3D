/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:45:16 by cpereira          #+#    #+#             */
/*   Updated: 2021/02/08 17:19:37 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	carrega_sprits(t_all *all, int o, double ang, double dist)
{
	double	dif_x;
	double	dif_y;
	double	dif_ang;

	all->fl.spr_visiveis = 0;
	while (o < all->fl.qtd_sprits)
	{
		dif_x = all->controle.meu_x - all->fl.sprits[o].sprit_x;
		dif_y = all->controle.meu_y - all->fl.sprits[o].sprit_y;
		ang = atan2(dif_y, dif_x);
		all->fl.sprits[o].dist_sprit = sqrt(dif_x * dif_x + dif_y * dif_y);
		ang = ang * 180 / 3.14159265;
		all->fl.sprits[o].dif_ang = all->controle.angulo_central - ang - 180;
		dif_ang = all->fl.sprits[o].dif_ang;
		dist = all->fl.sprits[o].dist_sprit;
		if ((fabs(dif_ang) <= 33 || (360 - fabs(dif_ang)) <= 33) && dist >= 12)
		{
			all->fl.vet[all->fl.spr_visiveis] = o;
			all->fl.spr_visiveis++;
		}
		o++;
	}
	ordena_sprits(all);
}

void	ordena_sprits(t_all *all)
{
	int o;
	int reserva;

	o = 0;
	while (o < all->fl.spr_visiveis - 1)
	{
		if (all->fl.sprits[all->fl.vet[o]].dist_sprit >
		all->fl.sprits[all->fl.vet[o + 1]].dist_sprit)
		{
			reserva = all->fl.vet[o + 1];
			all->fl.vet[o + 1] = all->fl.vet[o];
			all->fl.vet[o] = reserva;
			o = 0;
		}
		else
			o++;
	}
	rend_sprit_novo(all, 0, 0);
}

void	rend_sprit_novo(t_all *all, int x, int t_parede)
{
	int dist2;
	int i;
	int o;

	i = all->fl.spr_visiveis - 1;
	while (i >= 0)
	{
		o = all->fl.vet[i];
		all->fl.sprits[o].dist_sprit *=
		cos(fabs(all->fl.sprits[o].dif_ang) * (DIV_PI));
		t_parede = 6400 / all->fl.sprits[o].dist_sprit;
		all->fl.sprits[o].dif_ang = corrige_angulo(all->fl.sprits[o].dif_ang);
		dist2 = all->fl.tela_weight * (all->fl.sprits[o].dif_ang + 33) / 66;
		x = dist2 >= t_parede / 2 ? dist2 - t_parede / 2 : 0;
		all->extras.fim = dist2 >= t_parede / 2 ? t_parede + x
		: t_parede / 2 + dist2;
		all->extras.inicio = dist2 >= t_parede / 2 ? 0
		: all->extras.fim - dist2 * 2;
		continua_rend(all, x, t_parede, o);
		i--;
	}
}

void	continua_rend(t_all *all, int x, int t_parede, int o)
{
	float	fator;
	float	fator_y;
	int		cor;

	all->extras.obj = all->fl.sprits[o].modelo_sprit;
	fator = all->t_sprits[all->extras.obj].s_width / (float)t_parede;
	fator_y = all->t_sprits[all->extras.obj].s_height / (float)t_parede * 1.2;
	while (x < all->extras.fim && x < all->fl.tela_weight)
	{
		all->extras.ty = 0;
		all->extras.y = all->fl.tela_height / 2 - t_parede / 2 / 2;
		while (++all->extras.z < t_parede / 1.2)
		{
			cor = get_imagepixel(&all->t_sprits[all->extras.obj],
			all->extras.inicio * fator, all->extras.ty * fator_y);
			if (cor > 0 && all->fl.sprits[o].dist_sprit
			< all->distancia.distancia_f[x])
				my_mlx_pixel_put(&all->mlx.janela, x, all->extras.y, cor);
			all->extras.y++;
			all->extras.ty++;
		}
		all->extras.inicio++;
		all->extras.z = -1;
		x++;
	}
}

void	carrega_tex_sprits(t_all *all)
{
	all->t_sprits[2].img = importa_text(all->fl.sp, all, 6);
	all->t_sprits[3].img = importa_text(all->fl.s1, all, 7);
	all->t_sprits[4].img = importa_text(all->fl.s2, all, 8);
	all->t_sprits[2].addr = mlx_get_data_addr(all->t_sprits[2].img,
	&all->t_sprits[2].bits_per_pixel, &all->t_sprits[2].line_length,
	&all->t_sprits[2].endian);
	all->t_sprits[3].addr = mlx_get_data_addr(all->t_sprits[3].img,
	&all->t_sprits[3].bits_per_pixel, &all->t_sprits[3].line_length,
	&all->t_sprits[3].endian);
	all->t_sprits[4].addr = mlx_get_data_addr(all->t_sprits[4].img,
	&all->t_sprits[4].bits_per_pixel, &all->t_sprits[4].line_length,
	&all->t_sprits[4].endian);
}
