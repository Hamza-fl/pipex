/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:14:40 by hfalati           #+#    #+#             */
/*   Updated: 2025/02/02 13:14:40 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*validate_and_get_path(char **command, char **envp)
{
	char	*path;

	if (command[0][0] == '.' ||
		(command[0][0] == '/' && ft_strncmp(command[0], "/bin/", 5) != 0))
	{
		write(2, "Error: Command not found : ", 27);
		ft_putstr_fd(command[0], 2);
		exit(126);
	}
	if (command[0][0] == '/' && ft_strncmp(command[0], "/bin/", 5) == 0)
		path = ft_strdup(command[0]);
	else
		path = find_path(command[0], envp);
	if (!path)
	{
		write(2, "Error: Command not found : ", 27);
		ft_putstr_fd(command[0], 2);
		exit(127);
	}
	return (path);
}

void	execute(char *av, char **envp)
{
	int		i;
	char	**command;
	char	*path;

	command = ft_split(av, ' ');
	if (!command)
		error();
	path = validate_and_get_path(command, envp);
	if (execve(path, command, envp) == -1)
	{
		free(path);
		i = 0;
		while (command[i])
			free(command[i++]);
		free(command);
		error();
	}
}

char	*free_paths_return(char **paths, char *return_value)
{
	int	i;

	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (return_value);
}

char	*find_path(char *command, char **envp)
{
	int		i;
	char	*path;
	char	*path_part;
	char	**paths;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path_part = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_part, command);
		free(path_part);
		if (access(path, X_OK) == 0)
			return (free_paths_return(paths, path));
		free(path);
		i++;
	}
	return (free_paths_return(paths, 0));
}

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}
