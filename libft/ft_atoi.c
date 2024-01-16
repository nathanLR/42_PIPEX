/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:58:56 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/15 12:40:31 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	signe;
	int	result;

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
