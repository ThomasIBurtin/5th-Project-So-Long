/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_asset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: transfo <transfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:18:52 by tburtin           #+#    #+#             */
/*   Updated: 2023/12/05 16:02:23 by transfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	creation_asset(struct s_map *jeux)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	jeux->mur = mlx_xpm_file_to_image(jeux->mlx_ptr,
			"xpm/brique_bleu.xpm", &width, &height);
	jeux->vide = mlx_xpm_file_to_image(jeux->mlx_ptr,
			"xpm/floor.xpm", &width, &height);
	jeux->sortie = mlx_xpm_file_to_image(jeux->mlx_ptr,
			"xpm/porte.xpm", &width, &height);
	jeux->personnage = mlx_xpm_file_to_image(jeux->mlx_ptr,
			"xpm/mario.xpm", &width, &height);
	jeux->colectible = mlx_xpm_file_to_image(jeux->mlx_ptr,
			"xpm/piece.xpm", &width, &height);
}
