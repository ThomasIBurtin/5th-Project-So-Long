/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburtin <tburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 05:13:44 by transfo           #+#    #+#             */
/*   Updated: 2023/11/21 16:25:35 by tburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*remplir_ligne(char *reserve);
char	*nettoyer_reserve(char *reserve);
char	*remplir_reserve(int fd, char *reserve);
char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin_md(char *reserve, char *buffer);
char	*remplir_join(char *str, char *buffer, char *reserve);

#endif