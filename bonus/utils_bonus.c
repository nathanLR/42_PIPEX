/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:13:52 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/20 21:45:22 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_destroy_data(t_data *data)
{
	size_t	i;

	i = 0;
	if (data == NULL)
		return ;
	if (data->infile != NULL)
		free(data->infile);
	if (data->outfile != NULL)
		free(data->outfile);
	if (data->delimiter != NULL)
		free(data->delimiter);
	if (data->cmds != NULL)
	{
		while (i < ft_tablen((char **)data->cmds))
			ft_free_tab((void **)data->cmds[i++]);
		free(data->cmds);
	}
	free(data);
}

void	ft_manage_error(char *e_m, unsigned int e_t, t_data *data, int e_code)
{
	if (e_t == U_ERROR)
		ft_putendl_fd(e_m, STDERR_FILENO);
	else
		perror("Error");
	if (e_m != NULL)
		free(e_m);
	ft_destroy_data(data);
	exit(e_code);
}
