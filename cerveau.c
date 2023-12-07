/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cerveau.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburtin <tburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:09:51 by tburtin           #+#    #+#             */
/*   Updated: 2023/12/07 07:02:11 by tburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	deplacement(struct s_map *jeux, int x, int y)
{
	mlx_put_image_to_window(jeux->mlx_ptr, jeux->win_ptr, jeux->vide,
		jeux->positionxj * 32, jeux->positionyj * 32);
	jeux->terrain[jeux -> positionyj][jeux->positionxj] = '0';
	jeux->positionxj += x;
	jeux->positionyj += y;
	mlx_put_image_to_window(jeux->mlx_ptr, jeux->win_ptr, jeux->personnage,
		jeux-> positionxj * 32, jeux->positionyj * 32);
	jeux->terrain[jeux->positionyj][jeux->positionxj] = 'P';
}

void	algo(struct s_map *jeux, int x, int y)
{
	static int	nb_point = 0;
	static int	nb_mouvement = 0;

	nb_mouvement++;
	printf("Compte Total De Mouvement : %d\n", nb_mouvement);
	if ((jeux->terrain[jeux->positionyj + y][jeux->positionxj + x] == '0')
		|| (jeux->terrain[jeux->positionyj + y][jeux->positionxj + x] == 'C'))
	{
		if (jeux->terrain[jeux->positionyj + y][jeux->positionxj + x] == 'C')
			nb_point++;
		deplacement(jeux, x, y);
	}
	else if (jeux->terrain[jeux->positionyj + y][jeux->positionxj + x] == 'E')
	{
		if (nb_point == jeux->nb_collectible)
		{
			deplacement(jeux, x, y);
			fermeture_fenetre(jeux);
		}
	}
}

void	cerveau(int touche, struct s_map *jeux)
{
	if (touche == 119)
		algo(jeux, 0, -1);
	else if (touche == 97)
		algo(jeux, -1, 0);
	else if (touche == 115)
		algo(jeux, 0, 1);
	else if (touche == 100)
		algo(jeux, 1, 0);
}
