/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:13:52 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/18 23:12:32 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_destroy_data(t_data *data)
{
	int	i;

	i = 0;
	if (data == NULL)
		return ;
	if (data->infile != NULL)
		free(data->infile);
	if (data->outfile != NULL)
		free(data->outfile);
	if (data->cmds != NULL)
	{
		while (data->cmds[i] != NULL)
			ft_free_tab((void **)data->cmds[i++]);
		free(data->cmds);
	}
	if (data->hd_delimiter != NULL)
		free(data->hd_delimiter);
	if (data->hd_cmd1 != NULL)
		ft_free_tab((void **)data->hd_cmd1);
	if (data->hd_cmd2 != NULL)
		ft_free_tab((void **)data->hd_cmd2);
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
