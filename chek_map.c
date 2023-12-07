/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: transfo <transfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:19:02 by tburtin           #+#    #+#             */
/*   Updated: 2023/12/05 16:36:06 by transfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	chek_map(char *fichier, struct s_map *jeux)
{
	int		i;
	int		fd;
	char	*ligne;

	i = 0;
	fd = 0;
	ligne = NULL;
	i = chek_dimension(fichier, jeux);
	if (i == 0)
		return (0);
	fd = open(fichier, O_RDONLY);
	while (1)
	{
		ligne = get_next_line(fd);
		if (!ligne)
			break ;
		i = chek_ligne(ligne, jeux);
		free (ligne);
		if (i == 0)
			return (0);
	}
	close (fd);
	return (1);
}
