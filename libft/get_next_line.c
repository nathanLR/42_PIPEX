/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:27:27 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/26 16:59:20 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*content;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	content = ft_gnl_read(fd, content);
	if (!*content)
	{
		free(content);
		content = NULL;
		return (NULL);
	}
	line = ft_gnl_extract_line(content);
	content = ft_gnl_remove_line(content);
	return (line);
}
