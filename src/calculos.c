/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:58:06 by cpereira          #+#    #+#             */
/*   Updated: 2021/02/16 06:37:14 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	define_parede(t_all *all, int i, double difx, double dify)
{
	double d_x;
	double d_y;

	while (++i < all->fl.tela_weight)
	{
		difx = fmod((all->distancia.ultimo_x[i] + all->controle.meu_x), 10);
		dify = fmod((all->distancia.ultimo_y[i] + all->controle.meu_y), 10);
		d_y = all->distancia.ultimo_y[i];
		d_x = all->distancia.ultimo_x[i];
		all->distancia.parede[i] = ret_parede(difx, dify, d_x, d_y);
	}
	corrige_parede(all);
}

int		ret_parede(double difx, double dify, double d_x, double d_y)
{
	int ret;

	if (difx > dify)
	{
		ret = d_x < 0 && d_y < 0 ? 1 : 3;
		if (d_x > 0 && d_y < 0)
			ret = 4;
		if (d_x < 0 && d_y > 0)
			ret = 1;
		if (d_x < 0 && d_y > 0 && dify + difx >= 10)
			ret = 1;
		if (d_x <= 0 && d_y >= 0 && dify + difx <= 10)
			ret = 3;
	}
	else
	{
		ret = d_x < 0 && d_y < 0 ? 2 : 4;
		if (d_x > 0 && d_y < 0 && dify + difx >= 10)
			ret = 2;
		if (d_x >= 0 && d_y <= 0 && dify + difx <= 10)
			ret = 4;
	}
	return (ret);
}

void	corrige_parede(t_all *all)
{
	int	i;
	int	parede;
	int	ultima_parede;

	ultima_parede = all->distancia.parede[0];
	i = 1;
	while (i < all->fl.tela_weight - 8)
	{
		parede = all->distancia.parede[i];
		if (parede != ultima_parede && ultima_parede ==
		all->distancia.parede[i + 8])
			all->distancia.parede[i] = ultima_parede;
		else
			ultima_parede = parede;
		i++;
	}
	ajuste_vetor(all->renderiza, all);
}

void	ajuste_vetor(t_renderiza *renderiza, t_all *all)
{
	int i;
	int t_parede;

	i = 1;
	while (i < all->fl.tela_weight)
	{
		t_parede = 6400 / (all->distancia.distancia_f[i]);
		renderiza[i].limite_superior = round(all->fl.tela_height
		/ 2 - t_parede / 2);
		renderiza[i].limite_inferior = round(all->fl.tela_height
		/ 2 + t_parede / 2);
		renderiza[i].tam_parede = t_parede;
		i++;
	}
	renderiza4(all);
	mlx_put_image_to_window(all->mlx.mlx_ptr, all->mlx.win,
	all->mlx.janela.img, 0, 0);
}
