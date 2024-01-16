/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:25:16 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/11 15:16:25 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_strnsub(const char *sub, const char *little)
{
	while (*little)
		if (*little++ != *sub++)
			return (0);
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;

	l_len = ft_strlen(little);
	if (!big && !len)
		return (NULL);
	if (!*little)
		return ((char *)big);
	while (*big && len > 0 && l_len <= len)
	{
		if ((*big == *little) && ft_strnsub(big, little))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
