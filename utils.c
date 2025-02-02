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
#include "libft/libft.h"

void	execute(char *av, char **envp)
{
	int		i;
	char	**command;
	char	*path;

	command = ft_split(av, ' ');
	if (!command)
		error();
	path = find_path(command[0], envp);
	i = 0;
	if (!path)
	{
		while (command[i])
			free(command[i++]);
		free(command);
		write(2, "Error: Command not found\n", 25);
		exit(127);
	}
	if (execve(path, command, envp) == -1)
	{
		free(path);
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
