/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:29:45 by alvapari          #+#    #+#             */
/*   Updated: 2024/03/20 23:20:55 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_clean_buffer_aux(char *buffer_aux)
{
	char	*new_buffer;
	int count;
	int count2;
	int size_line;

	count2 = 0;
	count = 0;
	if (!buffer_aux)
		return NULL;
	while (buffer_aux[count] != '\n' && buffer_aux[count] != '\0')
		count++;
	size_line = (ft_strlen(buffer_aux) - count) + 1;
	new_buffer = malloc(sizeof(char) * size_line);
	if (!new_buffer)
		return (NULL);
	while(buffer_aux[++count])
		new_buffer[count2++] = buffer_aux[count];
	new_buffer[count2] = '\0';
	free(buffer_aux);
	return (new_buffer);
}

char    *ft_look_for_line(char *buffer_aux)
{
	char	*line;
	int count;
	int	count2;

	count = 0;
	count2 = 0;
	if (!buffer_aux && !buffer_aux[count])
		return (NULL);
	while (buffer_aux[count] != '\n' && buffer_aux[count] != '\0')
		count++;
	line = malloc((sizeof(char) * count) + 1 + buffer_aux[count] == '\n');
	if (!line)
		return (NULL);
	while (count2 < count)
	{
		line[count2] = buffer_aux[count2];
		count2++;
	}
	line[count2] = buffer_aux[count2];
	if (buffer_aux[count2++] == '\n')
		line[count2] = 0; printf("%s",line);
	return (line);
}

char	*ft_read_file(int fd, char *buffer_aux)
{
	char	*buffer;
	ssize_t	char_count;

	char_count = 1;
	buffer = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer_aux, '\n') && char_count > 0)
	{
		char_count = read(fd, buffer, BUFFER_SIZE);
		if (char_count == -1)
			return (free(buffer), free(buffer_aux), NULL);
		buffer[char_count] = 0;
		buffer_aux = ft_strjoin(buffer_aux, buffer);
		if (!buffer_aux)
			return (free(buffer), free(buffer_aux), NULL);
	}
	printf("%s",buffer_aux);
	free (buffer);
	return (buffer_aux);
}
 
char	*get_next_line(int fd)
{
	static char *buffer_aux;
	char *line;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer_aux = ft_read_file(fd, buffer_aux);
	if (!buffer_aux)
		return (NULL);
	line = ft_look_for_line(buffer_aux);
	buffer_aux = ft_clean_buffer_aux(buffer_aux); 
	return (line);
}

int main()
{
	int fd;
	int x;
	char *a;

	fd = open("41", O_RDONLY);
	if (fd < 0)
	{
		printf("Error");
		return 0;
	}
	a = get_next_line(fd);
	while(a){
		fflush(stdout);
		printf("esto es: %s", a);
		a = get_next_line(fd);
	}
		
}