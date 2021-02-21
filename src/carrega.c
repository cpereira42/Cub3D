/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carrega.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 12:45:01 by cezarpereir       #+#    #+#             */
/*   Updated: 2021/02/17 19:49:11 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	configura_mlx(t_all *all)
{
	all->mlx.mlx_ptr = mlx_init();
	all->mlx.win = mlx_new_window(all->mlx.mlx_ptr, all->fl.tela_weight,
	all->fl.tela_height, "Cub3D - - Cpereira -- 42SP");
	all->mlx.janela.img = mlx_new_image(all->mlx.mlx_ptr, all->fl.tela_weight,
	all->fl.tela_height);
	all->mlx.janela.addr = mlx_get_data_addr(all->mlx.janela.img,
	&all->mlx.janela.bits_per_pixel, &all->mlx.janela.line_length,
	&all->mlx.janela.endian);
}

void	grava_orientacao(t_all *all, int i, int j, char c)
{
	if (i == 0 || j == 0 || j == all->fl.tamanho_mapa_y
	|| i == all->fl.tamanho_mapa_x)
		all->erros.msg = "Mapa aberto";
	all->fl.meu_x = i;
	all->fl.meu_y = j;
	all->fl.orientacao = c;
	all->erros.posicao++;
}

void	colisao_parede(double *x, double *y, int angulo_inicial, t_all *all)
{
	if (localiza_ponto(*x, *y, all))
	{
		*y = all->controle.meu_y - round(0 * sin(angulo_inicial * DIV_PI));
		*x = all->controle.meu_x - round(0 * cos(angulo_inicial * DIV_PI));
	}
}

void	hook_tela(t_all *all)
{
	mlx_hook(all->mlx.win, 17, (1L << 17), saida_x, all);
	mlx_hook(all->mlx.win, 2, (1l << 0), tecla, all);
	mlx_hook(all->mlx.win, 9, 1L << 21, atualiza, all);
	mlx_loop(all->mlx.mlx_ptr);
}

int		atualiza(t_all *all)
{
	verifica_distancias(all, 0, 0, -1);
	carrega_sprits(all, 0, 0, 0);
	return (0);
}
