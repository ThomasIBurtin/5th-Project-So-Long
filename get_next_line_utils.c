/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburtin <tburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 05:13:28 by transfo           #+#    #+#             */
/*   Updated: 2023/11/21 14:33:15 by tburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*remplir_join(char *str, char *buffer, char *reserve)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (reserve[i] != '\0')
	{
		str[j] = reserve[i];
		i++;
		j++;
	}
	i = 0;
	while (buffer[i] != '\0')
	{
		str[j] = buffer[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(reserve);
	return (str);
}

char	*ft_strjoin_md(char *reserve, char *buffer)
{
	char	*str;

	if (!reserve)
	{
		reserve = malloc(sizeof(char) * 1);
		reserve[0] = '\0';
	}
	if (!reserve || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * (1 + ft_strlen(reserve) + ft_strlen(buffer)));
	if (!str)
		return (NULL);
	str = remplir_join(str, buffer, reserve);
	return (str);
}
