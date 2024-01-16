/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:31:29 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/11 16:06:10 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static unsigned int	ft_contains(const char *s, const char c)
{
	while (*s)
		if (*s++ == c)
			return (1);
	return (0);
}

static int	ft_get_trim_start(const char *s, const char *set)
{
	int	start;

	start = 0;
	while (ft_contains(set, *s++))
		start++;
	return (start);
}

static int	ft_get_trim_end(const char *s, const char *set)
{
	int	end;

	end = ft_strlen(s) - 1;
	while (end >= 0)
	{
		if (!ft_contains(set, s[end]))
			break ;
		end--;
	}
	return (end);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	start = ft_get_trim_start(s1, set);
	end = ft_get_trim_end(s1, set);
	res = ft_substr(s1, start, end - start + 1);
	return (res);
}
