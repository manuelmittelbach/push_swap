/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmittelb <mmittelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:31:18 by mmittelb          #+#    #+#             */
/*   Updated: 2025/08/01 14:16:35 by mmittelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

char	*ft_strjoin_char(char *s, char c)
{
	int		len;
	char	*new_str;
	int		i;

	len = 0;
	if (s)
		while (s[len])
			len++;
	new_str = malloc(len + 2);
	if (!new_str)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i++] = c;
	new_str[i] = '\0';
	free(s);
	return (new_str);
}

char	*get_next_line(int fd)
{
	char	buffer;
	char	*line;
	ssize_t	bytes_read;

	line = NULL;
	if (fd < 0)
		return (NULL);
	bytes_read = read(fd, &buffer, 1);
	while (bytes_read > 0)
	{
		line = ft_strjoin_char(line, buffer);
		if (!line)
			return (NULL);
		if (buffer == '\n')
			break ;
		bytes_read = read(fd, &buffer, 1);
	}
	if (bytes_read == -1)
	{
		free(line);
		return (NULL);
	}
	if (bytes_read == 0 && !line)
		return (NULL);
	return (line);
}
