/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:57:42 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/13 18:26:19 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	i = 0;
	if (start > s_len)
		len = 0;
	else if (s_len - start < len)
		len = s_len - start;
	result = ft_calloc(len + 1, sizeof(char));
	if (result)
		while (i < len)
			result[i++] = s[start++];
	return (result);
}
