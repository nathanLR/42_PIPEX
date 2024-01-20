/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:08:39 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/20 17:24:58 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <pipex.h>
#include <stdlib.h>

/*static void	ft_fill_data_cmds(char **argv, t_data *data)
{
	size_t	i;
	size_t	length;

	length = ft_tablen(argv) - 2;
	i = 0;
	while (i < length)
	{
		data->cmds[i] = ft_split(argv[i + 1], SPACE);
		if (data->cmds[i] == NULL)
			ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
		i++;
	}
}

static t_data	*ft_init_here_doc(char **argv, t_data *data)
{
	data->hd_delimiter = ft_strdup(argv[1]);
	if (data->hd_delimiter == NULL)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	data->hd_cmd1 = ft_split(argv[2], SPACE);
	if (data->hd_cmd1 == NULL)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	data->hd_cmd2 = ft_split(argv[3], SPACE);
	if (data->hd_cmd2 == NULL)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	data->infile = NULL;
	data->cmds = NULL;
	return (data);
}

static t_data	*ft_init_pipex(int argc, char **argv, t_data *data)
{
	data->infile = ft_strdup(argv[0]);
	if (data->infile == NULL)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	data->cmds = (char ***)ft_calloc(sizeof(char **), argc - 2 + 1);
	if (data->cmds == NULL)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	ft_fill_data_cmds(argv, data);
	data->hd_cmd1 = NULL;
	data->hd_cmd2 = NULL;
	data->hd_delimiter = NULL;
	return (data);
}
*/
static t_data	*ft_init_data(int argc, char **argv)
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
	data->outfile = ft_strdup(argv[argc - 1]);
	if (data->outfile == NULL)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	return (data);
}

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	argv++;
	argc--;
	if (argc != 4)
		ft_manage_error(ft_strdup(E_PARAMS), U_ERROR, NULL, EXIT_FAILURE);
	data = ft_init_data(argc, argv);
	ft_pipex(data, env);
	return (0);
}
