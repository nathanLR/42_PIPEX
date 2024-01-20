/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:11:26 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/19 16:38:27 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# define U_ERROR 2
# define P_ERROR 1
# define PID_CHILD 0
# define PIPE_ENTRY 1
# define PIPE_EXIT 0
# define SPACE ' '
# define E_PARAMS "Usage: ./pipex infile cmd1 ... cmd_n outfile"
# define E_HERE_DOC "Usage: ./pipex here_doc DELIMITER cmd1 cmd2 outfile"
# define E_NOT_EXISTS "zsh: no such file or directory: "
# define E_CMD_NOT_FOUND "zsh: command not found: "
# define E_PERM "zsh: permission denied: "
# define C_PERM 126
# define C_CMD_NOT_FOUND 127
# define HEREDOC 1
# define PIPEX 2

typedef struct s_data
{
	char	*infile;
	char	***cmds;
	char	*outfile;
	char	**hd_cmd1;
	char	**hd_cmd2;
	char	*hd_delimiter;
}	t_data;
void	ft_manage_error(char *e_m, unsigned int e_t, t_data *data, int e_code);
void	ft_pipex(t_data *data, char **env);
void	ft_execve(char **cmd, t_data *data, char **env);
void	ft_destroy_data(t_data *data);
void	ft_here_doc(t_data *data, char **env);
#endif
