/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:59:41 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/01 17:29:54 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	s_len;

	if (size)
	{
		s_len = ft_strlen(src);
		if (s_len >= size)
			s_len = size - 1;
		ft_memcpy(dest, src, s_len);
		*(dest + s_len) = 0;
	}
	return (ft_strlen(src));
}
