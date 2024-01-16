/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:07:21 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/11 16:50:23 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
	{
		while (n-- > 0)
			((char *)dest)[n] = ((char *)src)[n];
		return (dest);
	}
	else if (src > dest)
		ft_memcpy(dest, src, n);
	return (dest);
}
