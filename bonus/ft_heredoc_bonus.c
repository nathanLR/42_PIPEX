/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:49:12 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/19 17:52:59 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>
#include <libft.h>
#include <unistd.h>
/*
static void	ft_here_doc_child(int fds[2], t_data *data, char **env)
{
	char	*line_read;

	close(fds[PIPE_EXIT]);
	while(1)
	{
		line_read = get_next_line(STDIN_FILENO);
		if (ft_strcmp(line_read, data->hd_delimiter) == 0)
		{
			free(line_read);
			close(fds[PIPE_OUT]);
		}
		if (free != NULL)
		{
			ft_putstr_fd(fds[PIPE_OUT]);
			free(line_read);
		}
	}

}

static void ft_here_doc_parent(int fds[2], t_data *data, char **env)
{
	
}
*/
void	ft_here_doc(t_data *data, char **env)
{
	int		fds[2];
	pid_t	pid;

(void)env;
	if (pipe(fds) == -1)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
	//if (pid == PID_CHILD)
		//ft_here_doc_child(fds, data, env);
	//else
		//ft_here_doc_parent(fds, data, env);
	ft_destroy_data(data);
}
