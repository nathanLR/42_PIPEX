/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:11:26 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/17 23:04:26 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define U_ERROR 2
# define P_ERROR 1
# define PID_CHILD 0
# define PIPE_OUT 1
# define PIPE_IN 0
# define SPACE ' '
# define E_PARAMS "Usage: infile cmd1 cmd2 outfile"
# define E_NOT_EXISTS "zsh: not such file or directory: "
# define E_CMD_NOT_FOUND "zsh: command not found: "
# define E_PERM "zsh: permission denied: "
# define C_PERM 126
# define C_CMD_NOT_FOUND 127

typedef struct s_data
{
	char	*infile;
	char	**cmd1;
	char	**cmd2;
	char	*outfile;
}	t_data;
void	ft_manage_error(char *e_m, unsigned int e_t, t_data *data, int e_code);
void	ft_pipex(t_data *data, char **env);
void	ft_execve(char **cmd, t_data *data, char **env);
void	ft_destroy_data(t_data *data);
#endif
