/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_ligne.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburtin <tburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:17:09 by tburtin           #+#    #+#             */
/*   Updated: 2023/12/07 09:58:40 by tburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	chek_ligne_extremite(char *current_ligne, struct s_map *jeux)
{
	int	j;

	j = 0;
	while (j < jeux->nb_colonne)
	{
		if (current_ligne[j] != '1')
		{
			return (0);
		}
		j++;
	}
	return (j);
}

int	chek_caractere(char *str, int j)
{
	if (!(str[j] == 'E' || str[j] == 'P'
			|| str[j] == 'C' || str[j] == '1' || str[j] == '0'))
		return (0);
	return (1);
}

int	chek_ligne_milieu(char *ligne, struct s_map *jeux, int i)
{
	static int	e_trouve = 0;
	static int	p_trouve = 0;
	int			j;

	j = 0;
	if ((ligne[0] != '1') || (ligne[jeux->nb_colonne - 1] != '1'))
		return (0);
	while (j < jeux->nb_colonne)
	{
		if (chek_caractere(ligne, j) == 0)
			return (0);
		if (ligne[j] == 'E')
			e_trouve++;
		if (ligne[j] == 'P')
			p_trouve++;
		if (ligne[j] == 'C')
			jeux->nb_collectible++;
		j++;
	}
	if (i == jeux->nb_ligne)
	{
		if ((e_trouve != 1) || (p_trouve != 1) || (jeux->nb_collectible < 1))
			return (0);
	}
	return (1);
}

int	chek_ligne(char *current_ligne, struct s_map *jeux)
{
	int			result;
	static int	i = 1;

	result = 0;
	if (i == 1 || i == jeux->nb_ligne)
	{
		result = chek_ligne_extremite(current_ligne, jeux);
		if (result == 0)
			return (0);
	}
	result = chek_ligne_milieu(current_ligne, jeux, i);
	if (result == 0)
		return (0);
	i++;
	return (1);
}
