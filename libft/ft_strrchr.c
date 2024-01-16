/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:16:25 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/03 13:42:30 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			slen;
	unsigned char	c_cast;

	c_cast = (unsigned char)c;
	slen = ft_strlen(s);
	while ((int)slen >= 0)
	{
		if (s[slen] == c_cast)
			return ((char *)&s[slen]);
		slen--;
	}
	return (NULL);
}
