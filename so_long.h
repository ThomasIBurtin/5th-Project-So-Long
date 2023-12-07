/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: transfo <transfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:38:34 by tburtin           #+#    #+#             */
/*   Updated: 2023/12/05 16:14:14 by transfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "get_next_line.h"
# include <stdio.h>

struct s_map
{
	int		nb_colonne;
	int		nb_ligne;
	int		positionxj;
	int		positionyj;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*mur;
	void	*vide;
	void	*personnage;
	void	*sortie;
	void	*colectible;
	int		nb_collectible;
	char	**terrain;
};

int		main(int argc, char *argv[]);
int		chek_dimension(char *fichier, struct s_map *jeux);
int		chek_ligne(char *ligne, struct s_map *jeux);
int		chek_ligne_milieu(char *current_ligne, struct s_map *jeux, int i);
int		chek_ligne_extremite(char *current_ligne, struct s_map *jeux);
int		chek_map(char *fichier, struct s_map *jeux);
char	**ft_split(char const *str, char c);
void	fenetre(char *fichier, struct s_map *jeux);
void	creation_asset(struct s_map *jeux);
void	creation_map(char *ligne, struct s_map *jeux);
void	cerveau(int touche, struct s_map *jeux);
void	algo(struct s_map *jeux, int x, int y);
void	deplacement(struct s_map *jeux, int x, int y);
int		fermeture_fenetre(struct s_map *jeux);
int		keypress(int keycode, struct s_map *jeux);

#endif
