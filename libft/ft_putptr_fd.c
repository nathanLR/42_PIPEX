/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:25:30 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/15 15:11:48 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_putptr_fd(void *ptr, int fd)
{
	size_t	len;
	size_t	ptr_cast;

	if (!fd)
		return (0);
	if (!ptr)
		return (ft_putstr_fd("(nil)", fd));
	len = 0;
	ptr_cast = (size_t)ptr;
	len += ft_putstr_fd("0x", fd);
	return (len + ft_putnbr_base_fd(ptr_cast, "0123456789abcdef", 16, fd));
}
