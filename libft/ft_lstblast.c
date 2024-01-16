/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstblast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:11:25 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/29 12:16:46 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstblast(t_list *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && !lst->next->next)
		return (lst);
	lst = lst->next;
	return (ft_lstblast(lst));
}
