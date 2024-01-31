/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:08:39 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/26 09:13:41 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <pipex_bonus.h>
#include <stdlib.h>

static void	ft_fill_data_cmds(char **argv, t_data *data, int starter)
{
	size_t	i;
	size_t	length;

	length = ft_tablen(argv + starter) - 1;
	i = 0;
	while (i < length)
	{
		data->cmds[i] = ft_split(argv[i + starter], SPACE);
		if (data->cmds[i] == NULL)
			ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
		i++;
	}
}

static t_data	*ft_init_heredoc(int argc, char **argv, t_data *data)
{
	data->delimiter = ft_strdup(argv[1]);
	if (data->delimiter == NULL)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	data->cmds = (char ***)ft_calloc(sizeof(char **), argc - 3 + 1);
	if (data->cmds == NULL)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	ft_fill_data_cmds(argv, data, 2);
	data->infile = NULL;
	data->open_mode = O_WRONLY | O_CREAT | O_APPEND;
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
	ft_fill_data_cmds(argv, data, 1);
	data->delimiter = NULL;
	data->open_mode = O_WRONLY | O_CREAT | O_TRUNC;
	return (data);
}

static t_data	*ft_init_data(int argc, char **argv, t_bool is_heredoc)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data) * 1);
	if (data == NULL)
		ft_manage_error(NULL, P_ERROR, NULL, EXIT_FAILURE);
	data->is_heredoc = is_heredoc;
	if (data->is_heredoc)
		data = ft_init_heredoc(argc, argv, data);
	else
		data = ft_init_pipex(argc, argv, data);
	data->outfile = ft_strdup(argv[argc - 1]);
	if (data->outfile == NULL)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	return (data);
}

int	main(int argc, char **argv, char **env)
{
	t_data	*data;
	t_bool	is_heredoc;

	is_heredoc = 0;
	argv++;
	argc--;
	if (argv[0] != NULL && ft_strcmp(argv[0], "here_doc") == 0)
	{
		is_heredoc = 1;
		if (argc < 5)
			ft_manage_error(ft_strdup(E_HEREDOC), U_ERROR, NULL, EXIT_FAILURE);
	}
	else if (argc < 4)
		ft_manage_error(ft_strdup(E_PARAMS), U_ERROR, NULL, EXIT_FAILURE);
	data = ft_init_data(argc, argv, is_heredoc);
	ft_pipex(data, env);
	return (0);
}
