/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:03:08 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/28 14:04:13 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

long	ft_atol(const char *nptr)
{
	long	signe;
	long	result;

	result = 0;
	signe = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signe *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr) && *nptr)
	{
		result = result * 10 + (*nptr - 48);
		nptr++;
	}
	return (signe * result);
}
