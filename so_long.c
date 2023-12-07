/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: transfo <transfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:52:21 by tburtin           #+#    #+#             */
/*   Updated: 2023/12/05 16:27:35 by transfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	struct s_map	map;
	struct s_map	*jeux;
	int				fd;
	int				nb_read;
	char			lue[2024];

	jeux = &map;
	fd = 0;
	nb_read = 0;
	jeux->nb_collectible = 0;
	fd = chek_map(argv[1], jeux);
	if (fd == 0)
	{
		printf("Map Pas Conforme ");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	nb_read = read(fd, lue, 2024);
	jeux->terrain = ft_split(lue, '\n');
	if (!jeux->terrain)
		return (0);
	close(fd);
	fenetre(argv[1], jeux);
	return (nb_read + argc);
}
