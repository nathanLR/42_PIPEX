/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:17:34 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/15 14:52:14 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_putnbr_base_fd(size_t n, char *base, size_t size, int fd)
{
	size_t	res;
	size_t	quo;
	size_t	len;

	if (fd < 0)
		return (0);
	len = 0;
	res = n % size;
	quo = n / size;
	if (quo)
		len = ft_putnbr_base_fd(quo, base, size, fd);
	return (len + ft_putchar_fd(base[res], fd));
}
