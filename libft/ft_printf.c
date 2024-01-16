/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:43:09 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/26 16:36:55 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdarg.h>

static int	ft_handle_format(const char c, va_list ap)
{
	char	*s_hex_lower;
	char	*s_hex_upper;
	int		len;

	len = 0;
	s_hex_upper = "0123456789ABCDEF";
	s_hex_lower = "0123456789abcdef";
	if (c == 'c')
		len = ft_putchar_fd((char)va_arg(ap, int), 1);
	else if (c == 's')
		len = ft_putstr_fd(va_arg(ap, char *), 1);
	else if (c == 'p')
		len = ft_putptr_fd(va_arg(ap, void *), 1);
	else if (c == 'd' || c == 'i')
		len = ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == 'u')
		len = ft_putunbr_fd(va_arg(ap, unsigned int), 1);
	else if (c == 'x')
		len = ft_putnbr_base_fd(va_arg(ap, unsigned int), s_hex_lower, 16, 1);
	else if (c == 'X')
		len = ft_putnbr_base_fd(va_arg(ap, unsigned int), s_hex_upper, 16, 1);
	else if (c == '%')
		len = ft_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	if (!format)
		return (-1);
	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			len += ft_handle_format(*(format + 1), ap);
			format++;
		}
		else
			len += ft_putchar_fd(*format, 1);
		if (*format)
			format++;
	}
	va_end(ap);
	return (len);
}
