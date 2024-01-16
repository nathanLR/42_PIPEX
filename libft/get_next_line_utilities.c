/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utilities.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:27:27 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/26 16:59:52 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_gnl_remove_line(char *content)
{
	size_t	offset;
	char	*martyr;

	offset = 0;
	while (content[offset] && content[offset] != '\n')
		offset++;
	if (content[offset] == '\n')
		offset++;
	martyr = content;
	content = ft_strdup(martyr + offset);
	free(martyr);
	return (content);
}

char	*ft_gnl_extract_line(char *content)
{
	char	*line;
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (content[size] && content[size] != '\n')
		size++;
	if (content[size] == '\n')
		size++;
	line = (char *)ft_calloc(size + 1, sizeof(char));
	while (i < size && line)
	{
		line[i] = content[i];
		i++;
	}
	return (line);
}

char	*ft_gnl_read(int fd, char *content)
{
	char	*buffer;
	int		bytes_read;
	char	*martyr;

	if (!content)
		content = (char *)ft_calloc(1, sizeof(char));
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	martyr = NULL;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = 0;
		martyr = content;
		content = ft_strjoin(content, buffer);
		free(martyr);
		if (ft_strchr(content, '\n'))
			break ;
	}
	free(buffer);
	return (content);
}
