/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburtin <tburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:51:50 by tburtin           #+#    #+#             */
/*   Updated: 2023/12/03 15:52:03 by tburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freeup(char *strs)
{
	int	i;

	i = 0;
	while (strs[i] != '\0')
	{
		free(strs);
		i++;
	}
	free(strs);
}

int	nombre_mots(char *str, char c)
{
	int	i;
	int	nb_mots;

	i = 0;
	nb_mots = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			nb_mots++;
			while (str[i] != c && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (nb_mots);
		}
		i++;
	}
	return (nb_mots);
}

void	ft_strcpy(char *tab, char *str, char c, int j)
{
	int	i;

	i = 0;
	while (str[j] != '\0' && str[j] == c)
		j++;
	while (str[j + i] != c && str[j + i] != '\0')
	{
		tab[i] = str[j + i];
		i++;
	}
	tab[i] = '\0';
}

char	*creation_tabs(char *str, char c, int *k)
{
	char	*tab;
	int		j;
	int		p;

	j = *k;
	p = 0;
	tab = NULL;
	while (str[*k] != '\0')
	{
		if (str[*k] != c)
		{
			while (str[*k] != '\0' && str[*k] != c)
			{
				*k += 1;
				p++;
			}
			tab = (char *)malloc(sizeof(char) * (p + 1));
			if (tab == NULL)
				return (NULL);
			break ;
		}
		*k += 1;
	}
	ft_strcpy(tab, str, c, j);
	return (tab);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;
	int		i;
	int		nb;
	int		pos;

	if (str == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	nb = nombre_mots((char *)str, c);
	tab = (char **)malloc(sizeof(char *) * (nb + 1));
	if (tab == NULL)
		return (NULL);
	tab[nb] = NULL;
	while (i < nb)
	{
		tab[i] = creation_tabs(((char *)str), c, &pos);
		if (tab[i] == NULL)
		{
			ft_freeup(tab[i]);
		}
		i++;
	}
	return (tab);
}
