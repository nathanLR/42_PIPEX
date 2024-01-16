/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:54:01 by nle-roux          #+#    #+#             */
/*   Updated: 2023/11/28 14:36:58 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstpop(t_list **lst)
{
	t_list	*popped;

	if (!lst)
		return (NULL);
	popped = *lst;
	*lst = (*lst)->next;
	popped->next = NULL;
	return (popped);
}
