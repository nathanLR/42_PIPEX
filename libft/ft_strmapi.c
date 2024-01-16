/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:15:43 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/11 16:04:56 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	char	*result;
	size_t	idx;

	if (!s || !f)
		return (NULL);
	idx = 0;
	s_len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!result)
		return (NULL);
	while (idx < s_len)
	{
		result[idx] = f(idx, s[idx]);
		idx++;
	}
	result[idx] = 0;
	return (result);
}
