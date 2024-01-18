/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:49:12 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/18 23:07:56 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>
#include <libft.h>

void	ft_here_doc(t_data *data, char **env)
{
	(void)env;
	ft_printf("%s\n", data->hd_delimiter);
	ft_printf("%s\n", data->hd_cmd1);
	ft_printf("%s\n", data->hd_cmd2);
	ft_printf("%s\n", data->outfile);
}
