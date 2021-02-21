/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colisoes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:43:50 by cpereira          #+#    #+#             */
/*   Updated: 2021/02/16 16:38:58 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	verifica_mapa(t_all *all)
{
	int x;
	int y;
	int resp;

	x = 0;
	y = 0;
	resp = 0;
	while (x <= all->fl.tamanho_mapa_x)
	{
		y = 0;
		while (y <= all->fl.tamanho_mapa_y - 1)
		{
			if (all->fl.mapa[y][x] == '0')
				resp += verifica_redor(y, x, all);
			y++;
		}
		x++;
	}
	if (resp > 0)
		all->erros.msg = "Mapa inválido\n";
}

int		verifica_redor(int x, int y, t_all *all)
{
	int		k;
	int		l;
	char	c;

	k = -1;
	l = -1;
	while (k < 2)
	{
		l = -1;
		while (l < 2)
		{
			c = all->fl.mapa[x + k][y + l];
			if (((c < '0' || c > '2') && c != all->fl.orientacao) || c == ' ')
				return (1);
			l++;
		}
		k++;
	}
	return (0);
}

void	verifica_distancias(t_all *all, int x, int y, int p)
{
	int z;
	int angulo_inicial;

	angulo_inicial = all->controle.angulo_central;
	while (p++ < 3)
	{
		all->controle.media_x[p] = 0;
		all->controle.media_y[p] = 0;
		angulo_inicial += 90;
		z = 0;
		while ((int)z < 1000)
		{
			y = z * sin(angulo_inicial * DIV_PI) + all->controle.meu_y;
			x = z * cos(angulo_inicial * DIV_PI) + all->controle.meu_x;
			if (localiza_ponto(x, y, all))
				break ;
			z += 1;
		}
		all->distancia.obstaculos[p] = z;
		all->distancia.ultimo_x[p] = x;
		all->distancia.ultimo_y[p] = y;
	}
	desenha_visao(all, all->fl.tela_weight + 1,
	all->controle.angulo_central - 33, 0);
	define_parede(all, 0, 0, 0);
}

int		localiza_ponto(int x, int y, t_all *all)
{
	int p_x;
	int p_y;

	p_x = x / 10;
	p_y = y / 10;
	if (p_x <= 0)
		p_x = 0;
	if (p_y <= 0)
		p_y = 0;
	if (all->fl.mapa[p_x][p_y] == '1')
		return (1);
	else
		return (0);
}

void	desenha_visao(t_all *all, double cont, double angulo_inicial, double z)
{
	double x;
	double y;

	all->controle.passo_angulo = 66.f / all->fl.tela_weight;
	while (--cont >= 0)
	{
		z = 0;
		if (angulo_inicial >= 360)
			angulo_inicial -= 360;
		if (angulo_inicial <= 0)
			angulo_inicial += 360;
		while ((int)z < 1000)
		{
			y = z * sin(angulo_inicial * DIV_PI) + all->controle.meu_y;
			x = z * cos(angulo_inicial * DIV_PI) + all->controle.meu_x;
			if (localiza_ponto(x, y, all))
				break ;
			z += 0.1;
		}
		all->distancia.distancia_f[(int)cont] = z * cos(fabs(angulo_inicial -
		all->controle.angulo_central) * DIV_PI);
		all->distancia.ultimo_x[(int)cont] = z * cos(angulo_inicial * DIV_PI);
		all->distancia.ultimo_y[(int)cont] = z * sin(angulo_inicial * DIV_PI);
		angulo_inicial += all->controle.passo_angulo;
	}
}
