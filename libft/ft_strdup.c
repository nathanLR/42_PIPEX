/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:20:33 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/02 11:58:38 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*res;
	size_t	s;

	s = ft_strlen(src);
	res = (char *)malloc(sizeof(char) * (s + 1));
	if (!res)
		return (NULL);
	while (*src)
		*res++ = *src++;
	*res = 0;
	return (res - s);
}
