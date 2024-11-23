/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:14:35 by alvapari          #+#    #+#             */
/*   Updated: 2024/03/23 17:43:27 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_look_for_line(char *buffer_aux)
{
	char	*line;
	int		cnt;

	if (!buffer_aux[0])
		return (NULL);
	cnt = 0;
	while (buffer_aux[cnt] && buffer_aux[cnt] != '\n')
		cnt++;
	line = malloc(sizeof(char) * (cnt + 2));
	if (!line)
		return (0);
	cnt = 0;
	while (buffer_aux[cnt] && buffer_aux[cnt] != '\n')
	{
		line[cnt] = buffer_aux[cnt];
		cnt++;
	}
	if (buffer_aux[cnt] == '\n')
	{
		line[cnt] = buffer_aux[cnt];
		cnt++;
	}
	line[cnt] = '\0';
	return (line);
}

char	*ft_clean_aux(char *buffer_aux)
{
	int		cnt;
	int		cnt2;
	char	*new_aux;

	cnt = 0;
	cnt2 = 0;
	while (buffer_aux[cnt] && buffer_aux[cnt] != '\n')
		cnt++;
	if (!buffer_aux[cnt])
	{
		free(buffer_aux);
		return (0);
	}
	new_aux = malloc(ft_strlen(buffer_aux) - cnt + 1);
	if (!new_aux)
		return (NULL);
	cnt++;
	while (buffer_aux[cnt])
		new_aux[cnt2++] = buffer_aux[cnt++];
	new_aux[cnt2] = '\0';
	free(buffer_aux);
	return (new_aux);
}

char	*ft_read_file(char *buffer_aux, int fd)
{
	char	*buffer;
	int		read_chars;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	read_chars = 1;
	while (!ft_strchr(buffer_aux, '\n') && read_chars != 0)
	{
		read_chars = read(fd, buffer, BUFFER_SIZE);
		if (read_chars == -1)
			return (free(buffer), free(buffer_aux), NULL);
		buffer[read_chars] = '\0';
		buffer_aux = ft_strjoin(buffer, buffer_aux);
	}
	free(buffer);
	return (buffer_aux);
}

char	*get_next_line(int fd)
{
	static char	*buffer_aux[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer_aux[fd] = ft_read_file(buffer_aux[fd], fd);
	if (!buffer_aux[fd])
		return (NULL);
	line = ft_look_for_line(buffer_aux[fd]);
	buffer_aux[fd] = ft_clean_aux(buffer_aux[fd]);
	return (line);
}
