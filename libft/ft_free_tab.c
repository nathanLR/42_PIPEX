/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:31:53 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/13 18:32:14 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_free_tab(void **tab)
{
	char	**tmp;
	
	tmp = (char **)tab;
	while (*tmp)
		free(*tmp++);
	free(tab);
}
