/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:45:16 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/15 11:34:08 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	trigger;
	int	words;

	words = 0;
	trigger = 1;
	while (*s)
	{
		if (*s != c && trigger)
		{
			words++;
			trigger = 0;
		}
		if (*s == c)
			trigger = 1;
		s++;
	}
	return (words);
}

static int	ft_get_subsize(char const *s, char c)
{
	int	size;

	size = 0;
	while (*s)
	{
		if (*s == c)
			break ;
		size++;
		s++;
	}
	return (size);
}

void	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	tab = (char **)ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	i = 0;
	if (!tab)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			tab[i] = ft_substr(s, 0, ft_get_subsize(s, c));
			if (!tab[i++])
			{
				ft_free_split(tab);
				break ;
			}
			s += ft_get_subsize(s, c);
		}
		if (*s)
			s++;
	}
	return (tab);
}
