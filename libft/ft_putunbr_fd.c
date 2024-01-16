/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:29:03 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/15 12:42:43 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_putunbr_fd(unsigned int n, int fd)
{
	unsigned int	res;
	unsigned int	quo;
	size_t			len;

	if (fd < 0)
		return (0);
	len = 0;
	res = n % 10;
	quo = n / 10;
	if (quo)
		len += ft_putunbr_fd(quo, fd);
	return (ft_putchar_fd(res + 48, fd) + len);
}
