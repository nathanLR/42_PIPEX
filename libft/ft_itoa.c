/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:33:16 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/11 17:25:19 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_strsize(int n)
{
	int	size;

	size = 1;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n / 10)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static void	ft_fill_itoa(char *s, int n, int size)
{
	int	res;
	int	quo;

	res = n % 10;
	quo = n / 10;
	if (quo)
		ft_fill_itoa(s, quo, size - 1);
	*(s + size - 1) = res + 48;
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;
	char	*tmp;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_strsize(n);
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	tmp = result;
	*(result + size) = 0;
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	ft_fill_itoa(result, n, size);
	return (tmp);
}
