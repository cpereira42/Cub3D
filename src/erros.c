/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:40:48 by cpereira          #+#    #+#             */
/*   Updated: 2021/02/17 15:06:09 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	trata_erro(t_all *all)
{
	int fd;

	if (all->erros.resolucao == 0)
		all->erros.msg = "Sem resolução\n";
	if (all->erros.resolucao > 1)
		all->erros.msg = "Duas resoluções\n";
	if ((fd = open(all->fl.no, O_RDONLY)) < 0)
		all->erros.msg = "Erro na Textura Norte\n";
	if (all->erros.no > 1)
		all->erros.msg = "Norte duplicado\n";
	if ((fd = open(all->fl.so, O_RDONLY)) < 0)
		all->erros.msg = "SErro na Textura Sul\n";
	if (all->erros.so > 1)
		all->erros.msg = "Sul duplicado\n";
	if ((fd = open(all->fl.ea, O_RDONLY)) < 0)
		all->erros.msg = "Erro na Textura Leste\n";
	if (all->erros.ea > 1)
		all->erros.msg = "Leste duplicado\n";
	if ((fd = open(all->fl.we, O_RDONLY)) < 0)
		all->erros.msg = "Erro na Textura Oeste\n";
	if (all->erros.we > 1)
		all->erros.msg = "Oeste duplicado\n";
	if ((fd = open(all->fl.sp, O_RDONLY)) < 0)
		all->erros.msg = "Erro na Textura Sprite\n";
	continua_tratamento(all);
}

void	continua_tratamento(t_all *all)
{
	int fd;

	if (all->erros.sp != 1)
		all->erros.msg = "Sprite duplicado\n";
	if (all->erros.f != 1)
		all->erros.msg = "Cor chão duplicado ou inválida\n";
	if (all->erros.c != 1)
		all->erros.msg = "Cor Céu duplicado ou inválida\n";
	if (all->erros.posicao == 0)
		all->erros.msg = "Sem Orientação\n";
	if ((fd = open(all->fl.sp, O_RDONLY)) < 0)
		all->erros.msg = "Erro na Textura Sprite\n";
	if (all->erros.posicao > 1)
		all->erros.msg = "Orientação duplicadas\n";
	if (all->erros.no <= 0 || all->erros.so <= 0 || all->erros.we <= 0
	|| all->erros.ea <= 0)
		all->erros.msg = "Falta textura\n";
	if (all->fl.tela_height <= 0 || all->fl.tela_height <= 0)
		all->erros.msg = "Resolução inválida\n";
	if (all->fl.tela_height < 500 || all->fl.tela_height > 800)
		all->erros.msg = "Altura de 500 a 800\n";
	if (all->fl.tela_weight < 700 || all->fl.tela_weight > 1080)
		all->erros.msg = "Largura de 700 a 1080\n";
}

char	*verifica_argumentos(int argc, char **argv)
{
	char **ret;

	if (argc == 1)
		return ("Sem mapa\n");
	if (argc > 3)
		return ("Muitos argumentos\n");
	ret = ft_split(argv[1], '.');
	if (!ft_strncmp(ret[1], ".", 3))
		return ("Mapa diferente de .cub\n");
	if (argc == 3)
		if (ft_strncmp(argv[2], "--save", 6))
			return ("Argumentos inválidos\n");
	free_array((void*)ret);
	return ("");
}

void	ler_arquivo(char *path, t_all *all)
{
	int		fd;
	int		ret;
	char	*line;
	int		posicao;

	posicao = 0;
	if ((fd = open(path, O_RDONLY)) < 0)
	{
		ft_putstr_fd("Mapa não encontrado\n", 1);
		exit(0);
	}
	else
		while ((ret = get_next_line(fd, &line)))
		{
			if (line[0] != '\0')
				verifica_arquivo(line, all);
			free(line);
			line = NULL;
			posicao++;
		}
	check_n_free(line);
	close(fd);
}

void	destroy_imagens(t_all *all)
{
	int i;

	i = 1;
	while (i <= 4)
	{
		if (all->textura[i].img != NULL)
			mlx_destroy_image(all->mlx.mlx_ptr, all->textura[i].img);
		i++;
	}
	mlx_destroy_image(all->mlx.mlx_ptr, all->mlx.janela.img);
}
