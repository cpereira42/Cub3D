/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:41:11 by cpereira          #+#    #+#             */
/*   Updated: 2021/02/16 17:36:16 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copia_mapa(char *line, t_all *all)
{
	int tamanho_split;

	tamanho_split = ft_strlen(line);
	if (line[0] == '1' || line[0] == '0' || line[0] == ' ')
	{
		all->fl.mapa_line = ft_strjoin(all->fl.mapa_line, line);
		all->fl.mapa_line = ft_strjoin(all->fl.mapa_line, "*\n");
		if (all->fl.tamanho_mapa_x < tamanho_split)
			all->fl.tamanho_mapa_x = tamanho_split;
		all->fl.tamanho_mapa_y++;
	}
	else
	{
		if (all->fl.tamanho_mapa_x > 0)
			all->erros.msg = "Formato inválido\n";
	}
}

void	verifica_arquivo(char *line, t_all *all)
{
	char	**ret2;

	copia_mapa(line, all);
	ret2 = ft_split(line, ' ');
	if ((ft_strncmp(ret2[0], "R", 1) == 0) && ft_strlen(ret2[0]) == 1)
	{
		if (ret2[1] != '\0' && ret2[2] != '\0' && ret2[3] == '\0')
		{
			if (verifica_numero(ret2[1]) || verifica_numero(ret2[2]))
				all->erros.msg = "Resoluçao inválida\n";
			all->fl.tela_weight = ft_atoi(ret2[1]);
			all->fl.tela_height = ft_atoi(ret2[2]);
			all->erros.resolucao++;
		}
		else
			all->fl.tela_weight = 0;
	}
	if ((line[0] == 'F' || line[0] == 'C') && (ret2[2] != NULL))
		all->erros.msg = "Cor Inválida\n";
	if (ret2[1] != NULL && line[0] != 'R' && line[0] != '1'
	&& line[0] != '0' && line[0] != ' ')
		armazena_entradas(all, ret2[0], ret2[1]);
	free_array((void*)ret2);
}

void	armazena_entrada_sprites(t_all *all, int local, char *entrada)
{
	if (local == 0)
	{
		if (entrada[0] == '.' && entrada[1] == '.')
			all->erros.sp = -99;
		if (all->erros.sp == 0)
			all->fl.sp = ft_strdup(entrada);
		all->erros.sp++;
		all->fl.s1 = "./texturas/trofeu.xpm";
		all->fl.s2 = "./texturas/p2.xpm";
		all->fl.s3 = "./texturas/p2.xpm";
	}
	if (local == 1)
	{
		all->fl.floor = convert_rgb(entrada, all, 'F');
		all->erros.f++;
	}
	if (local == 2)
	{
		all->fl.ceil = convert_rgb(entrada, all, 'C');
		all->erros.c++;
	}
	entrada = NULL;
}

void	armazena_entrada_paredes(t_all *all, int local, char *entrada)
{
	if (local == 0)
	{
		if (all->erros.no++ == 0)
			all->fl.no = ft_strdup(entrada);
	}
	if (local == 1)
	{
		if (all->erros.so++ == 0)
			all->fl.so = ft_strdup(entrada);
	}
	if (local == 2)
	{
		if (all->erros.we++ == 0)
			all->fl.we = ft_strdup(entrada);
	}
	if (local == 3)
	{
		if (all->erros.ea++ == 0)
			all->fl.ea = ft_strdup(entrada);
	}
	if (entrada[0] == '.' && entrada[1] == '.')
		all->erros.ea = -99;
	entrada = NULL;
}

void	gera_mapa(t_all *all, int i, int p, int j)
{
	char c;

	while (all->fl.mapa_line[p] != '\0')
	{
		if (all->fl.mapa_line[p] == '\n')
		{
			i++;
			j = 0;
		}
		else
		{
			c = all->fl.mapa_line[p];
			all->fl.mapa[i][j] = all->fl.mapa_line[p];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
				grava_orientacao(all, i, j, all->fl.mapa_line[p]);
			if (c == '2')
				adiciona_sprit(all, i, j);
			j++;
		}
		p++;
	}
}
