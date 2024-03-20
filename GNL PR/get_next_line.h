/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:31:12 by alvapari          #+#    #+#             */
/*   Updated: 2024/03/20 23:03:45 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_get_line(char *stack);
char	*ft_read_file(int fd, char *stack);
char	*ft_stack_refill(char *stack);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
int		ft_strlen(char *str);

#endif