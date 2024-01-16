/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:37:56 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/15 12:34:46 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	if (!s || fd < 0)
		return (0);
	len = 0;
	len += ft_putstr_fd(s, fd);
	len += ft_putchar_fd('\n', fd);
	return (len);
}
