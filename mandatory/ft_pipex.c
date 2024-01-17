/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:27:03 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/17 23:16:09 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <libft.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

static void	ft_process_child(int fds[2], t_data *data, char **env)
{
	int	input_file_fd;

	input_file_fd = open(data->infile, O_RDONLY);
	if (input_file_fd == -1)
		ft_manage_error(ft_strjoin(E_NOT_EXISTS, data->infile), U_ERROR, data, EXIT_FAILURE);
	if (dup2(input_file_fd, STDIN_FILENO) == -1)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	if (dup2(fds[PIPE_OUT], STDOUT_FILENO) == -1)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	close(fds[PIPE_IN]);
	close(input_file_fd);
	close(fds[PIPE_OUT]);
	ft_execve(data->cmd1, data, env);
	exit(EXIT_SUCCESS);
}

static void	ft_process_parent(int fds[2], t_data *data, char **env)
{
	int	output_file_fd;

	output_file_fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (output_file_fd == -1)
		ft_manage_error(ft_strjoin(E_PERM, data->outfile), U_ERROR, data, EXIT_FAILURE);
	if (dup2(output_file_fd, STDOUT_FILENO) == -1)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	if (dup2(fds[PIPE_IN], STDIN_FILENO) == -1)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	close(fds[PIPE_OUT]);
	close(fds[PIPE_IN]);
	close(output_file_fd);
	wait(NULL);
	ft_execve(data->cmd2, data, env);
}

void	ft_pipex(t_data *data, char **env)
{
	int	fds[2];
	int	pid;

	if (pipe(fds) == -1)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	if (pid == PID_CHILD)
		ft_process_child(fds, data, env);
	else
		ft_process_parent(fds, data, env);
	ft_destroy_data(data);
}
