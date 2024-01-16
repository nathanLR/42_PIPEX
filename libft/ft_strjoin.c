/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:36:17 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/11 19:16:05 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	tot_len;

	if (!s1 || !s2)
		return (NULL);
	tot_len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)ft_calloc((tot_len + 1), sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcat(res, s1, tot_len + 1);
	ft_strlcat(res, s2, tot_len + 1);
	return (res);
}
