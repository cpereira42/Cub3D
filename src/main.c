/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:58:45 by cpereira          #+#    #+#             */
/*   Updated: 2021/02/17 18:43:44 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	adiciona_sprit(t_all *all, int i, int j)
{
	if (i == 0 || j == 0 || i == all->fl.tamanho_mapa_y - 1 ||
	j == all->fl.tamanho_mapa_x - 1)
		all->erros.msg = "Mapa aberto\n";
	if (all->ultimo_sp > 3)
		all->ultimo_sp = 2;
	else
		all->ultimo_sp++;
	all->fl.sprits[all->fl.qtd_sprits].sprit_x = i * 10 + 5;
	all->fl.sprits[all->fl.qtd_sprits].sprit_y = j * 10 + 5;
	all->fl.sprits[all->fl.qtd_sprits].modelo_sprit = all->ultimo_sp;
	all->fl.qtd_sprits++;
}

void	reseta_flags(t_all *all)
{
	all->ultimo_sp = 2;
	all->fl.tamanho_mapa_x = -1;
	all->fl.tamanho_mapa_y = 0;
	all->fl.mapa_line = ft_strdup("");
	all->fl.qtd_sprits = 0;
	all->erros.resolucao = 0;
	all->erros.no = 0;
	all->erros.so = 0;
	all->erros.ea = 0;
	all->erros.we = 0;
	all->erros.f = 0;
	all->erros.c = 0;
	all->erros.sp = 0;
	all->erros.posicao = 0;
	all->fl.qtd_sprits = 0;
	all->r = 0;
	all->g = 0;
	all->b = 0;
	all->fl.ceil = 0;
	all->fl.floor = 0;
	all->textura[1].img = NULL;
	all->textura[2].img = NULL;
	all->textura[3].img = NULL;
	all->textura[4].img = NULL;
}

void	*importa_text(char *entrada, t_all *all, int posic)
{
	char **ret;
	void *saida;

	saida = NULL;
	ret = ft_split(entrada, '.');
	if (posic <= 4)
	{
		if (ret[1] != NULL && !ft_strncmp(ret[1], "xpm", 3))
			saida = mlx_xpm_file_to_image(all->mlx.mlx_ptr, entrada,
			&all->textura[posic].s_width, &all->textura[posic].s_height);
		else
			all->erros.msg = "textura em formato inválida\n";
	}
	else
	{
		if (ret[1] != NULL && !ft_strncmp(ret[1], "xpm", 3))
			saida = mlx_xpm_file_to_image(all->mlx.mlx_ptr, entrada, &all->
			t_sprits[posic - 4].s_width, &all->t_sprits[posic - 4].s_height);
		else
			all->erros.msg = "textura em formato inválida\n";
	}
	free_array((void*)ret);
	if (ft_strlen(all->erros.msg) > 3)
		sai(all, all->erros.msg);
	return (saida);
}

void	carrega_texturas(t_all *all)
{
	all->textura[1].img = importa_text(all->fl.no, all, 1);
	all->textura[2].img = importa_text(all->fl.we, all, 2);
	all->textura[3].img = importa_text(all->fl.ea, all, 3);
	all->textura[4].img = importa_text(all->fl.so, all, 4);
	all->textura[1].addr = mlx_get_data_addr(all->textura[1].img,
	&all->textura[1].bits_per_pixel, &all->textura[1].line_length,
	&all->textura[1].endian);
	all->textura[2].addr = mlx_get_data_addr(all->textura[2].img,
	&all->textura[2].bits_per_pixel, &all->textura[2].line_length,
	&all->textura[2].endian);
	all->textura[3].addr = mlx_get_data_addr(all->textura[3].img,
	&all->textura[3].bits_per_pixel, &all->textura[3].line_length,
	&all->textura[3].endian);
	all->textura[4].addr = mlx_get_data_addr(all->textura[4].img,
	&all->textura[4].bits_per_pixel, &all->textura[4].line_length,
	&all->textura[4].endian);
}

int		main(int argc, char **argv)
{
	t_all	all;

	reseta_flags(&all);
	all.erros.msg = verifica_argumentos(argc, argv);
	ler_arquivo(argv[1], &all);
	gera_mapa(&all, 0, 0, 0);
	verifica_mapa(&all);
	trata_erro(&all);
	if (ft_strlen(all.erros.msg) > 3)
		sai(&all, all.erros.msg);
	all.controle.angulo_central = verifica_angulo(&all);
	configura_mlx(&all);
	carrega_texturas(&all);
	carrega_tex_sprits(&all);
	tamanho_bloco(&all);
	verifica_distancias(&all, 0, 0, -1);
	carrega_sprits(&all, 0, 0, 0);
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
		grava_bmp(&all, 0);
	mlx_put_image_to_window(all.mlx.mlx_ptr, all.mlx.win,
	all.mlx.janela.img, 0, 0);
	hook_tela(&all);
	return (0);
}
