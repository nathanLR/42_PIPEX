/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:43:05 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/15 12:41:23 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_putnbr_fd(int n, int fd)
{
	int	res;
	int	quo;
	int	len;

	if (fd < 0)
		return (0);
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	len = 0;
	if (n < 0)
	{
		len += ft_putchar_fd('-', fd);
		n *= -1;
	}
	res = n % 10;
	quo = n / 10;
	if (quo)
		len += ft_putnbr_fd(quo, fd);
	return (ft_putchar_fd(res + 48, fd) + len);
}
