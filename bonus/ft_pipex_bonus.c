/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:27:03 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/19 19:20:25 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>
#include <libft.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
/*
static void	ft_process_child(int fds[2], t_data *data, char **env)
{
	int	input_file_fd;

	input_file_fd = open(data->infile, O_RDONLY);
	if (input_file_fd == -1)
		ft_manage_error(ft_strjoin(E_NOT_EXISTS, data->infile),
			U_ERROR, data, EXIT_FAILURE);
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
		ft_manage_error(ft_strjoin(E_PERM, data->outfile),
			U_ERROR, data, EXIT_FAILURE);
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
*/

void	ft_pipex(t_data *data, char **env)
{
	size_t	i;
	int		input_file_fd;
	int		output_file_fd;
	int		fds[2];
	pid_t	pid;

	i = 0;
	input_file_fd = open(data->infile, O_RDONLY);
	output_file_fd = open(data->outfile, O_WRONLY | O_CREAT | O_APPEND, 0664);
	dup2(input_file_fd, STDIN_FILENO);
	while (i < ft_tablen((char **)data->cmds) - 1)
	{
		pipe(fds);
		pid = fork();
		if (pid == 0)
		{
			close(fds[0]);
			dup2(fds[1], STDOUT_FILENO);
			ft_execve(data->cmds[i], data, env);
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(NULL);
			close(fds[1]);
			dup2(fds[0], STDIN_FILENO);
		}
		i++;
	}
	dup2(output_file_fd, STDOUT_FILENO);
	ft_execve(data->cmds[i], data, env);
	
}
/*void	ft_pipex(t_data *data, char **env)
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

	int		fds[2];
	pid_t	pid;
	size_t	i;
	int		input_file_fd;
	int		output_file_fd;
	i = 0;

	input_file_fd = open(data->infile, O_RDONLY);
	if (input_file_fd == -1)
		ft_manage_error(ft_strjoin(E_NOT_EXISTS, data->infile),
			U_ERROR, data, EXIT_FAILURE);
	if (dup2(input_file_fd, STDIN_FILENO) == -1)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	while (i < ft_tablen((char **)data->cmds) - 1)
	{
		if (pipe(fds) == -1)
			ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
		pid = fork();
		if (pid == -1)
			ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
		if (pid == PID_CHILD)
		{
			close(fds[PIPE_EXIT]);
			if (dup2(fds[PIPE_ENTRY], STDOUT_FILENO) == -1)
				ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
			ft_execve(data->cmds[i], data, env);
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(NULL);
			close(fds[PIPE_ENTRY]);
			if (dup2(fds[PIPE_EXIT], STDIN_FILENO) == -1)
				ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
		}
		i++;
	}
	output_file_fd = open(data->outfile, O_WRONLY | O_CREAT | O_APPEND, 0664);
	if (output_file_fd == -1)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	if (dup2(fds[PIPE_EXIT], STDIN_FILENO) == -1)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	ft_execve(data->cmds[i], data, env);

}*/
