/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_dimension.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: transfo <transfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:28:37 by tburtin           #+#    #+#             */
/*   Updated: 2023/12/05 16:19:27 by transfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	chek_dimension(char *fichier, struct s_map *jeux)
{
	int		fd;
	char	*ligne;

	fd = 0;
	ligne = NULL;
	jeux ->nb_ligne = 0;
	jeux ->nb_colonne = 0;
	fd = open(fichier, O_RDONLY);
	while (1)
	{
		ligne = get_next_line(fd);
		if (!ligne)
			break ;
		jeux->nb_colonne = 0;
		while (ligne[jeux->nb_colonne] != '\0')
			jeux->nb_colonne++;
		jeux->nb_ligne++;
		free(ligne);
	}
	close (fd);
	if (jeux->nb_ligne >= jeux->nb_colonne)
		return (0);
	return (1);
}
