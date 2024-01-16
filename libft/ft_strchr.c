/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:39:38 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/03 13:40:51 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			s_len;
	size_t			i;
	unsigned char	c_cast;

	c_cast = (unsigned char)c;
	i = 0;
	s_len = ft_strlen(s);
	while (i < s_len + 1)
	{
		if (*s == c_cast)
			return ((char *)s);
		s++;
		i++;
	}
	return (NULL);
}
