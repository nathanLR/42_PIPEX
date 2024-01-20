/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:41:09 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/20 17:40:57 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>
#include <libft.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static char	*ft_get_path_env(char **env)
{
	while (*env != NULL)
	{
		if (ft_strnstr(*env, "PATH=", ft_strlen("PATH=")) != NULL)
			return (*env + 5);
		env++;
	}
	return (NULL);
}

static char	*ft_build_path(char *var, char *cmd)
{
	char	*part_one;
	char	*part_two;

	part_one = ft_strjoin(var, "/");
	part_two = ft_strjoin(part_one, cmd);
	if (part_one != NULL)
		free(part_one);
	return (part_two);
}

static char	*ft_get_cmd_path(char *cmd, char **env)
{
	char	*path_var;
	char	**paths;
	char	*path_exec;
	int		var;

	var = 0;
	path_var = ft_get_path_env(env);
	paths = ft_split(path_var, ':');
	if (paths == NULL)
		return (NULL);
	while (paths[var] != NULL)
	{
		path_exec = ft_build_path(paths[var], cmd);
		if (access(path_exec, F_OK | X_OK) == 0)
		{
			ft_free_tab((void **)paths);
			return (path_exec);
		}
		if (path_exec != NULL)
			free(path_exec);
		var++;
	}
	ft_free_tab((void **)paths);
	return (NULL);
}

void	ft_execve(char **cmd, t_data *data, char **env)
{
	char	*path;

	if (ft_strchr(cmd[0], '/') != NULL)
	{
		if (execve(cmd[0], cmd, env) == -1)
			ft_manage_error(ft_strjoin(E_NOT_EXISTS, cmd[0]),
				U_ERROR, data, C_CMD_NOT_FOUND);
	}
	else
	{
		path = ft_get_cmd_path(cmd[0], env);
		if (path == NULL)
			ft_manage_error(ft_strjoin(E_CMD_NOT_FOUND, cmd[0]),
				U_ERROR, data, C_CMD_NOT_FOUND);
		if (execve(path, cmd, env) == -1)
		{
			free(path);
			ft_manage_error(NULL, P_ERROR, data, EXIT_FAILURE);
		}
		free(path);
	}
}
