/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:13:23 by cpereira          #+#    #+#             */
/*   Updated: 2021/02/16 16:42:10 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		saida_x(void)
{
	exit(0);
	return (0);
}

void	sai(t_all *all, char *msg)
{
	all->erros.msg = "";
	if (ft_strlen(msg) > 3)
		ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(msg, 1);
	all->fl.no != NULL ? free(all->fl.no) : 0;
	all->fl.so != NULL ? free(all->fl.so) : 0;
	all->fl.we != NULL ? free(all->fl.we) : 0;
	all->fl.ea != NULL ? free(all->fl.ea) : 0;
	all->fl.sp != NULL ? free(all->fl.sp) : 0;
	if (all->textura[1].img != NULL)
		mlx_destroy_image(all->mlx.mlx_ptr, all->textura[1].img);
	if (all->textura[2].img != NULL)
		mlx_destroy_image(all->mlx.mlx_ptr, all->textura[2].img);
	if (all->textura[3].img != NULL)
		mlx_destroy_image(all->mlx.mlx_ptr, all->textura[3].img);
	if (all->textura[4].img != NULL)
		mlx_destroy_image(all->mlx.mlx_ptr, all->textura[4].img);
	if (all->mlx.janela.img != NULL)
		mlx_destroy_image(all->mlx.mlx_ptr, all->mlx.janela.img);
	if (all->mlx.mlx_ptr && all->mlx.win)
		mlx_destroy_window(all->mlx.mlx_ptr, all->mlx.win);
	if (all->mlx.mlx_ptr)
		free(all->mlx.mlx_ptr);
	all->fl.mapa_line != NULL ? free(all->fl.mapa_line) : 0;
	exit(0);
}

void	armazena_entradas(t_all *all, char *desc, char *valor)
{
	if (desc[1] != 0)
	{
		if (desc[0] == 'N' && desc[1] == 'O' && ft_strlen(desc) == 2)
			armazena_entrada_paredes(all, 0, valor);
		else if (desc[0] == 'S' && desc[1] == 'O' && ft_strlen(desc) == 2)
			armazena_entrada_paredes(all, 1, valor);
		else if (desc[0] == 'W' && desc[1] == 'E' && ft_strlen(desc) == 2)
			armazena_entrada_paredes(all, 2, valor);
		else if (desc[0] == 'E' && desc[1] == 'A' && ft_strlen(desc) == 2)
			armazena_entrada_paredes(all, 3, valor);
		else
			all->erros.msg = "Caracter inválido\n";
	}
	else
	{
		if (desc[0] == 'S' && ft_strlen(desc) == 1)
			armazena_entrada_sprites(all, 0, valor);
		else if (desc[0] == 'F' && ft_strlen(desc) == 1)
			armazena_entrada_sprites(all, 1, valor);
		else if (desc[0] == 'C' && ft_strlen(desc) == 1)
			armazena_entrada_sprites(all, 2, valor);
		else
			all->erros.msg = "Caracter inválido\n";
	}
}
