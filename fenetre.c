/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fenetre.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburtin <tburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:45:56 by tburtin           #+#    #+#             */
/*   Updated: 2023/12/07 07:02:55 by tburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_terrain(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	fermeture_fenetre(struct s_map *jeux)
{
	free_terrain(jeux->terrain);
	mlx_destroy_image(jeux->mlx_ptr, jeux->vide);
	mlx_destroy_image(jeux->mlx_ptr, jeux->personnage);
	mlx_destroy_image(jeux->mlx_ptr, jeux->sortie);
	mlx_destroy_image(jeux->mlx_ptr, jeux->colectible);
	mlx_destroy_image(jeux->mlx_ptr, jeux->mur);
	mlx_destroy_window(jeux->mlx_ptr, jeux->win_ptr);
	mlx_destroy_display(jeux->mlx_ptr);
	free(jeux->mlx_ptr);
	exit(0);
}

int	keypress(int keycode, struct s_map *jeux)
{
	if (keycode == 65307)
		fermeture_fenetre(jeux);
	else
		cerveau(keycode, jeux);
	return (0);
}

void	fenetre(char *fichier, struct s_map *jeux)
{
	int		fd;
	char	*ligne;

	fd = 0;
	ligne = NULL;
	jeux->mlx_ptr = mlx_init();
	jeux->win_ptr = mlx_new_window(jeux->mlx_ptr, 32 * jeux->nb_colonne,
			32 * jeux->nb_ligne, "SO_LONG");
	creation_asset (jeux);
	fd = open(fichier, O_RDONLY);
	while (1)
	{
		ligne = get_next_line(fd);
		if (!ligne)
			break ;
		creation_map(ligne, jeux);
		free(ligne);
	}
	close(fd);
	mlx_key_hook(jeux->win_ptr, keypress, jeux);
	mlx_hook(jeux->win_ptr, 17, 0, fermeture_fenetre, jeux);
	mlx_loop(jeux->mlx_ptr);
}
