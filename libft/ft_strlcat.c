/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:12:20 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/11 19:12:04 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;

	if (dst == NULL && !size)
		return (0);
	len = ft_strlen(dst);
	if (len > size)
		return (size + ft_strlen(src));
	return (len + ft_strlcpy(dst + len, src, size - len));
}
