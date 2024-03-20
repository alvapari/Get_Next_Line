/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:24:53 by alvapari          #+#    #+#             */
/*   Updated: 2024/03/20 23:19:03 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*nstr;
	size_t	count;
	size_t	count2;

	count = 0;
	count2 = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	nstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (nstr == NULL)
		return (NULL);
	while (s1[count])
		nstr[count2++] = s1[count++];
	count = 0;
	while (s2[count] != '\0')
		nstr[count2++] = s2[count++];
	nstr[count2++] = '\0';
	free(s1);
	return (nstr);
}

char	*ft_strchr(char *s, int c)
{
	int	count;
	if (!s)
		return 0;
	count = 0;
	while (s[count] != '\0' && s[count] != (char)c)
		count++;
	if (s[count] == (char)c)
		return ((char *) &s[count]);
	return (0);
}

int	ft_strlen(char *str)
{
	unsigned int	count;
	if (!str)
		return 0;
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}
