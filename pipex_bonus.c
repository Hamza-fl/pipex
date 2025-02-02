/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:14:54 by hfalati           #+#    #+#             */
/*   Updated: 2025/02/02 13:14:54 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

void	here_doc(char *command, int ac);
void	child_process(char *av, char **envp);

void	handle_here_doc(char **av, int ac, char **envp)
{
	int	i;
	int	file_out;
	int	pib;

	i = 3;
	file_out = open_file(av[ac - 1], 0);
	here_doc(av[2], ac);
	while (i < ac - 2)
		child_process(av[i++], envp);
	pib = fork();
	if (pib == 0)
	{
		dup2(file_out, STDOUT_FILENO);
		execute(av[ac - 2], envp);
	}
	while (wait(NULL) != -1)
		;
	close(file_out);
}

void	handle_regular_files(char **av, int ac, char **envp)
{
	int	i;
	int	file_out;
	int	file_in;
	int	pib;

	i = 2;
	file_out = open_file(av[ac - 1], 1);
	file_in = open_file(av[1], 2);
	dup2(file_in, STDIN_FILENO);
	while (i < ac - 2)
		child_process(av[i++], envp);
	pib = fork();
	if (pib == 0)
	{
		dup2(file_out, STDOUT_FILENO);
		execute(av[ac - 2], envp);
	}
	while (wait(NULL) != -1)
		;
	close(file_out);
}

int	main(int ac, char **av, char **envp)
{
	if (ac >= 5)
	{
		if (ft_strncmp(av[1], "here_doc", 8) == 0)
			handle_here_doc(av, ac, envp);
		else
			handle_regular_files(av, ac, envp);
		return (0);
	}
	min_error();
	return (1);
}

void	here_doc(char *command, int ac)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	if (ac < 6)
		min_error();
	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, command, ft_strlen(command) == 0))
				exit (EXIT_SUCCESS);
			write (fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

void	child_process(char *av, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(av, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}
