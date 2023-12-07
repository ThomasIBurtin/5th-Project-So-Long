/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburtin <tburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:16:11 by tburtin           #+#    #+#             */
/*   Updated: 2023/12/07 07:17:58 by tburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	afficher(void *img, int image_x, int image_y, struct s_map *jeux)
{
	mlx_put_image_to_window(jeux->mlx_ptr, jeux->win_ptr,
		img, image_x, image_y);
}

void	creation_map(char *ligne, struct s_map *jeux)
{
	static int	image_y = 0;
	int			image_x;

	image_x = 0;
	while ((image_x / 32) < jeux->nb_colonne)
	{
		if (ligne[image_x / 32] == '0')
			afficher(jeux->vide, image_x, image_y, jeux);
		else if (ligne[image_x / 32] == '1')
			afficher(jeux->mur, image_x, image_y, jeux);
		else if (ligne[image_x / 32] == 'E')
			afficher(jeux->sortie, image_x, image_y, jeux);
		else if (ligne[image_x / 32] == 'C')
			afficher(jeux->colectible, image_x, image_y, jeux);
		else if (ligne[image_x / 32] == 'P')
		{
			afficher(jeux->personnage, image_x, image_y, jeux);
			jeux->positionxj = image_x / 32;
			jeux->positionyj = image_y / 32;
		}
		image_x += 32;
	}
	image_y += 32;
}
