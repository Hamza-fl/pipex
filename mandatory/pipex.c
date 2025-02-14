/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:15:00 by hfalati           #+#    #+#             */
/*   Updated: 2025/02/02 13:15:00 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(char **av, char **envp, int *fd);
void	child_process(char **av, char **envp, int *fd);

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;

	if (ac != 5)
		min_error();
	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == 0)
		child_process(av, envp, fd);
	pid2 = fork();
	if (pid2 < 0)
		error();
	if (pid2 == 0)
		parent_process(av, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

void	child_process(char **av, char **envp, int *fd)
{
	int	file_in;

	close(fd[0]);
	file_in = open(av[1], O_RDONLY);
	if (file_in == -1)
	{
		close(fd[1]);
		error();
	}
	if (dup2(file_in, STDIN_FILENO) == -1)
	{
		close(file_in);
		close(fd[1]);
		error();
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		close(file_in);
		close(fd[1]);
		error();
	}
	close(fd[1]);
	close(file_in);
	execute(av[2], envp);
}

void	parent_process(char **av, char **envp, int *fd)
{
	int	file_out;

	close(fd[1]);
	file_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_out == -1)
	{
		close(fd[0]);
		error();
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		close(file_out);
		close(fd[0]);
		error();
	}
	if (dup2(file_out, STDOUT_FILENO) == -1)
	{
		close(file_out);
		close(fd[0]);
		error();
	}
	close(fd[0]);
	close(file_out);
	execute(av[3], envp);
}

void	min_error(void)
{
	write (2, "Error: Bad argument\n", 20);
	write (2, "Ex: ./pipex <file1> <cmd1> <...> <cmd2> <file2>\n", 48);
	exit(EXIT_SUCCESS);
}
