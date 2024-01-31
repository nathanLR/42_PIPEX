/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:27:03 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/27 11:56:18 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>
#include <libft.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

static void	ft_process_child(int fds[2], char **cmd, t_data *data, char **env)
{
	close(fds[PIPE_EXIT]);
	if (dup2(fds[PIPE_ENTRY], STDOUT_FILENO) == -1)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	close(fds[PIPE_ENTRY]);
	ft_execve(cmd, data, env);
	exit(EXIT_SUCCESS);
}

static void	ft_process_cmd(char **cmd, t_data *data, char **env)
{
	int		fds[2];
	pid_t	pid;

	if (pipe(fds) == -1)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	if (pid == PID_CHILD)
		ft_process_child(fds, cmd, data, env);
	else
	{
		wait(NULL);
		close(fds[PIPE_ENTRY]);
		if (dup2(fds[PIPE_EXIT], STDIN_FILENO) == -1)
			ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
		close(fds[PIPE_EXIT]);
	}
}

static void	ft_gnl_heredoc(int fds[2], char *delimiter, t_data *data)
{
	char	*gnl;

	close(fds[PIPE_EXIT]);
	while (1)
	{
		ft_printf("pipex heredoc> ");
		gnl = get_next_line(STDIN_FILENO);
		if (ft_strncmp(gnl, delimiter, ft_strlen(delimiter)) == 0)
		{
			free(gnl);
			break ;
		}
		ft_putstr_fd(gnl, fds[PIPE_ENTRY]);
		free(gnl);
	}
	close(fds[PIPE_ENTRY]);
	ft_destroy_data(data);
	exit(EXIT_SUCCESS);
}

static void	ft_is_heredoc(t_data *data)
{
	int		fds[2];
	pid_t	pid;

	if (pipe(fds) == -1)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	if (pid == PID_CHILD)
		ft_gnl_heredoc(fds, data->delimiter, data);
	else
	{
		wait(NULL);
		close(fds[PIPE_ENTRY]);
		if (dup2(fds[PIPE_EXIT], STDIN_FILENO) == -1)
			ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
		close(fds[PIPE_EXIT]);
	}
}

void	ft_pipex(t_data *data, char **env)
{
	int		input_file_fd;
	int		output_file_fd;
	size_t	i;

	i = 0;
	if (data->is_heredoc)
		ft_is_heredoc(data);
	else
	{
		input_file_fd = open(data->infile, O_RDONLY);
		if (input_file_fd == -1)
			ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
		dup2(input_file_fd, STDIN_FILENO);
		close(input_file_fd);
	}
	while (i < ft_tablen((char **)data->cmds) - 1)
		ft_process_cmd(data->cmds[i++], data, env);
	output_file_fd = open(data->outfile, data->open_mode, 0664);
	if (output_file_fd == -1)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	dup2(output_file_fd, STDOUT_FILENO);
	close(output_file_fd);
	ft_execve(data->cmds[i], data, env);
}
