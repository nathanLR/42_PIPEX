/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:58:17 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/11 19:25:08 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*result;
	long long	m_size;

	m_size = nmemb * size;
	if (m_size < 0 || ((long long)nmemb < 0 && (long long)size < 0))
		return (NULL);
	result = malloc(m_size);
	if (!result)
		return (NULL);
	ft_bzero(result, m_size);
	return (result);
}
