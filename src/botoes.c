/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   botoes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 19:48:11 by cpereira          #+#    #+#             */
/*   Updated: 2021/02/17 19:50:23 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		tecla(int keycode, t_all *all)
{
	int		ang_ini;
	double	x;
	double	y;

	if (keycode == TECLA_W)
		ang_ini = all->controle.angulo_central;
	if (keycode == TECLA_D && all->distancia.obstaculos[2] > 4)
		ang_ini = all->controle.angulo_central - 90;
	if (keycode == TECLA_A && all->distancia.obstaculos[0] > 4)
		ang_ini = all->controle.angulo_central + 90;
	if (keycode == TECLA_S && all->distancia.obstaculos[1] > 4)
		ang_ini = all->controle.angulo_central - 180;
	if (keycode == TECLA_A || keycode == TECLA_D || keycode == TECLA_S ||
	keycode == TECLA_W)
	{
		y = round(3 * sin(ang_ini * (3.14159265 / 180))) + all->controle.meu_y;
		x = round(3 * cos(ang_ini * (3.14159265 / 180))) + all->controle.meu_x;
		verifica_colisao(&x, &y, ang_ini, all);
		all->controle.meu_x = x;
		all->controle.meu_y = y;
	}
	continua_teclas(keycode, all);
	return (0);
}

void	continua_teclas(int keycode, t_all *all)
{
	if (keycode == TECLA_R)
		all->controle.angulo_central -= 4;
	if (keycode == TECLA_L)
		all->controle.angulo_central += 4;
	if (all->controle.angulo_central >= 360)
		all->controle.angulo_central = all->controle.angulo_central - 360;
	if (all->controle.angulo_central < 0)
		all->controle.angulo_central = all->controle.angulo_central + 360;
	if (keycode == TECLA_ESC)
		sai(all, "");
	verifica_distancias(all, 0, 0, -1);
	carrega_sprits(all, 0, 0, 0);
}

void	grava_bmp(t_all *all, int fd)
{
	int				tamanho_arquivo;
	unsigned char	c[54];

	fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, 444);
	if (!fd)
		ft_putstr_fd("Erro ao gerar imagem", 1);
	ft_bzero(&c, 54);
	tamanho_arquivo = 54 + all->fl.tela_height * all->fl.tela_weight *
	all->mlx.janela.bits_per_pixel / 8;
	c[0] = 'B';
	c[1] = 'M';
	converte(&c[2], tamanho_arquivo, 4);
	converte(&c[10], 54, 4);
	converte(&c[14], 40, 4);
	converte(&c[18], all->fl.tela_weight, 4);
	converte(&c[22], all->fl.tela_height, 4);
	converte(&c[26], 1, 2);
	converte(&c[28], 32, 2);
	write(fd, &c, 54);
	grava_cor(fd, all);
	close(fd);
	saida_x();
}

void	grava_cor(int fd, t_all *all)
{
	int		x;
	int		y;
	int		i;

	y = all->fl.tela_height - 1;
	x = 0;
	i = 0;
	all->bmp = malloc(sizeof(int) * all->fl.tela_weight * all->fl.tela_height);
	while (y >= 0)
	{
		x = 0;
		while (x < all->fl.tela_weight)
		{
			all->bmp[i++] = get_imagepixel(&all->mlx.janela, x, y);
			x++;
		}
		y--;
	}
	write(fd, &all->bmp[0], all->fl.tela_height * all->fl.tela_weight * 4);
	free(all->bmp);
}

void	verifica_colisao(double *x, double *y, int angulo_inicial, t_all *all)
{
	int		o;
	double	dif_x;
	double	dif_y;
	double	dist;

	o = 0;
	while (o <= all->fl.qtd_sprits)
	{
		dif_x = *x - all->fl.sprits[o].sprit_x;
		dif_y = *y - all->fl.sprits[o].sprit_y;
		dist = sqrt(dif_x * dif_x + dif_y * dif_y);
		if (all->fl.sprits[o].modelo_sprit == 3 && dist <= 10)
		{
			all->fl.sprits[o].sprit_x = 0;
			all->fl.sprits[o].sprit_y = 0;
		}
		if (all->fl.sprits[o].modelo_sprit == 2 && dist <= 12)
		{
			*y = all->controle.meu_y - round(0 * sin(angulo_inicial * DIV_PI));
			*x = all->controle.meu_x - round(0 * cos(angulo_inicial * DIV_PI));
			all->vidas--;
		}
		o++;
	}
	colisao_parede(x, y, angulo_inicial, all);
}
