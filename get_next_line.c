/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburtin <tburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 05:13:36 by transfo           #+#    #+#             */
/*   Updated: 2023/11/21 14:56:59 by tburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*remplir_ligne(char *reserve)
{
	int		i;
	char	*ligne;

	i = 0;
	if (reserve[i] == '\0')
		return (NULL);
	while (reserve[i] != '\n' && reserve[i] != '\0')
		i++;
	ligne = malloc(sizeof(char) * (i + 2));
	if (!ligne)
		return (NULL);
	i = 0;
	while (reserve[i] != '\n' && reserve[i] != '\0')
	{
		ligne[i] = reserve[i];
		i++;
	}
	if (reserve[i] == '\n')
	{
		ligne [i] = '\n';
		i++;
	}
	ligne[i] = '\0';
	return (ligne);
}

char	*nettoyer_reserve(char *reserve)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (reserve[i] != '\n' && reserve[i] != '\0')
		i++;
	if (reserve[i] == '\0')
	{
		free(reserve);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(reserve) - i + 1));
	if (!str)
		return (NULL);
	while (reserve[++i] != '\0')
	{
		str[j] = reserve[i];
		j++;
	}
	str[j] = '\0';
	free(reserve);
	return (str);
}

char	*remplir_reserve(int fd, char *reserve)
{
	char	*buffer;
	int		nb_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nb_read = 1;
	while (!ft_strchr(reserve, '\n') && nb_read != 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nb_read] = '\0';
		reserve = ft_strjoin_md(reserve, buffer);
	}
	free(buffer);
	return (reserve);
}

char	*get_next_line(int fd)
{
	char		*ligne;
	static char	*reserve;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	reserve = remplir_reserve(fd, reserve);
	if (!reserve)
		return (NULL);
	ligne = remplir_ligne(reserve);
	reserve = nettoyer_reserve(reserve);
	return (ligne);
}
