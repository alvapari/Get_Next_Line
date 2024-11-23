/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:20:46 by alvapari          #+#    #+#             */
/*   Updated: 2024/03/23 15:59:55 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

char	*get_next_line(int fd);
char	*ft_look_for_line(char *buffer_aux);
char	*ft_read_file(char *buffer_aux, int fd);
char	*ft_clean_aux(char *buffer_aux);
char	*ft_strjoin(char *buffer, char *buffer_aux);
char	*ft_strchr(char *str, char c);
int		ft_strlen(char *str);

#endif