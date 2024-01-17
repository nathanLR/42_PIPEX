/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:08:39 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/17 23:15:26 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <pipex.h>
#include <stdlib.h>

static t_data	*ft_init_data(char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data) * 1);
	if (data == NULL)
		ft_manage_error(NULL, P_ERROR, NULL, EXIT_FAILURE);
	data->infile = ft_strdup(argv[0]);
	if (data->infile == NULL)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	data->cmd1 = ft_split(argv[1], SPACE);
	if (data->cmd1 == NULL)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	data->cmd2 = ft_split(argv[2], SPACE);
	if (data->cmd2 == NULL)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	data->outfile = ft_strdup(argv[3]);
	if (data->outfile == NULL)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	return (data);
}

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	if (argc != 5)
		ft_manage_error(ft_strdup(E_PARAMS), U_ERROR, NULL, EXIT_FAILURE);
	data = ft_init_data(++argv);
	ft_pipex(data, env);
	return (0);
}
