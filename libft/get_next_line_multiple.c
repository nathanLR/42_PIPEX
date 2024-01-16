/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_multiple.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:27:27 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/26 17:00:47 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*get_next_line_multiple(int fd)
{
	static char	*content[FD_OPEN_LIMIT];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	content[fd] = ft_gnl_read(fd, content[fd]);
	if (!*content[fd])
	{
		free(content[fd]);
		content[fd] = NULL;
		return (NULL);
	}
	line = ft_gnl_extract_line(content[fd]);
	content[fd] = ft_gnl_remove_line(content[fd]);
	return (line);
}
