/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:10:30 by cpereira          #+#    #+#             */
/*   Updated: 2021/02/17 18:40:07 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define DIV_PI 0.01745333
# define TECLA_W 119
# define TECLA_S 115
# define TECLA_A 97
# define TECLA_D 100
# define TECLA_L 65361
# define TECLA_R 65363
# define TECLA_ESC 65307

typedef struct	s_sprit {
	int			sprit_x;
	int			sprit_y;
	int			modelo_sprit;
	double		dist_sprit;
	double		dif_ang;
}				t_sprit;

typedef struct	s_extras {
	int			inicio;
	int			fim;
	int			z;
	int			obj;
	double		distx;
	double		disty;
	double		inicio_x;
	double		inicio_y;
	int			y;
	int			ty;
}				t_extras;

typedef struct	s_t_flags
{
	int			tamanho_mapa_x;
	int			tamanho_mapa_y;
	int			tela_weight;
	int			tela_height;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*sp;
	char		*s1;
	char		*s2;
	char		*s3;
	int			floor;
	int			ceil;
	char		mapa[990][990];
	char		*mapa_line;
	int			meu_x;
	int			meu_y;
	char		orientacao;
	int			tamanho_x_minimapa;
	int			tamanho_y_minimapa;
	int			qtd_sprits;
	int			spr_visiveis;
	t_sprit		sprits[50];
	int			vet[99];
}				t_flags;

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			tipo;
	int			s_width;
	int			s_height;
}				t_data;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_data		janela;
}				t_mlx;

typedef struct	s_erros
{
	int			resolucao;
	int			no;
	int			so;
	int			ea;
	int			we;
	int			f;
	int			c;
	int			sp;
	int			posicao;
	char		*msg;
}				t_erros;

typedef struct	s_controle
{
	int			angulo_central;
	int			minimapa_x;
	int			minimapa_y;
	int			meu_x;
	int			meu_y;
	float		passo_angulo;
	int			tamanho_min_x;
	int			tamanho_min_y;
	int			tamanho_bloco;
	int			tamanho_borda;
	int			media_x[8];
	int			media_y[8];
}				t_controle;

typedef struct	s_distancia
{
	int			obstaculo_f;
	int			obstaculos[4];
	double		ultimo_x[1080];
	double		ultimo_y[1080];
	int			parede[1080];
	double		distancia_f[1080];
}				t_distancia;

typedef struct	s_renderiza
{
	int			limite_superior;
	int			limite_inferior;
	int			tam_parede;
}				t_renderiza;

typedef struct	s_all
{
	t_mlx		mlx;
	t_flags		fl;
	t_controle	controle;
	t_distancia	distancia;
	t_data		textura[8];
	t_data		t_sprits[50];
	t_renderiza	renderiza[1080];
	t_erros		erros;
	t_extras	extras;
	int			vidas;
	int			ultimo_sp;
	int			r;
	int			g;
	int			b;
	int			*bmp;
}				t_all;

void			allocacao(t_all *all);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				tecla(int keycode, t_all *all);
int				get_imagepixel(t_data *data, int x, int y);
void			tamanho_bloco(t_all *all);
void			cria_minimapa(t_all *all, int x, int y, int cor);
char			**ft_split(const char *s, char c);
int				count_size(char const *s, char c);
int				localiza_ponto(int x, int y, t_all *all);
void			verifica_distancias(t_all *all, int x, int y, int p);
void			desenha_visao(t_all *all, double cont,
double angulo_inicial, double z);
void			define_parede(t_all *all, int i, double difx, double dify);
void			ajuste_vetor(t_renderiza *renderiza, t_all *all);
void			corrige_parede(t_all *all);
void			limpa_flags(t_all *all);
void			renderiza4(t_all *all);
void			rend_sprit(t_all *all, double angulo, int dist, int tipo);
void			gera_mapa(t_all *all, int i, int p, int j);
void			verifica_colisao(double *x, double *y,
int angulo_inicial, t_all *all);
void			armazena_entrada_paredes(t_all *all, int local, char *entrada);
void			armazena_entrada_sprites(t_all *all, int local, char *entrada);
void			carrega_sprits(t_all *all, int o, double ang, double dist);
void			verifica_mapa(t_all *all);
int				verifica_redor(int x, int y, t_all *all);
void			carrega_text_sprits(t_all *all);
char			*verifica_argumentos(int argc, char **argv);
void			trata_erro(t_all *all);
int				convert_rgb(char *cor, t_all *all, char c);
void			converte(unsigned char *c, unsigned int value, int size);
void			grava_bmp(t_all *all, int fd);
void			grava_cor(int fd, t_all *all);
void			ordena_sprits(t_all *all);
void			continua_tratamento(t_all *all);
void			continua_teclas(int keycode, t_all *all);
void			continua_rend(t_all *all, int x, int t_parede, int o);
void			rend_sprit_novo(t_all *all, int x, int t_parede);
void			adiciona_sprit(t_all *all, int i, int j);
double			corrige_angulo (double entrada);
void			carrega_sprits(t_all *all, int o, double ang, double dist);
void			verifica_arquivo(char *line, t_all *all);
int				ret_parede (double difx, double dify, double d_x, double d_y);
void			*importa_text(char *entrada, t_all *all, int posicao);
void			acao(t_all *all, int parede, int x, int z);
void			inicio(t_all *all, int parede, int x);
void			grava_orientacao (t_all *all, int i, int j, char c);
void			configura_mlx(t_all *all);
void			carrega_texturas(t_all *all);
void			sai(t_all *all, char *msg);
void			armazena_entradas(t_all *all, char *desc, char *valor);
void			colisao_parede(double *x, double *y, int angulo_inicial,
t_all *all);
int				conta_caracter (char *entrada);
int				verifica_numero(char *entrada);
void			check_n_free(void *ptr);
void			desenha_map(t_all *all);
void			free_array(void **array);
void			destroy_imagens(t_all *all);
int				saida_x(void);
void			limite_cores (t_all *all, char c);
void			carrega_tex_sprits(t_all *all);
int				verifica_angulo(t_all *all);
void			ler_arquivo(char *path, t_all *all);
int				atualiza(t_all *all);
void			hook_tela (t_all *all);
#endif
