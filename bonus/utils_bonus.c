/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:15:14 by hfalati           #+#    #+#             */
/*   Updated: 2025/02/02 13:15:14 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	min_error(void)
{
	write (2, "Error: Bad argument\n", 20);
	write (2, "Ex: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 48);
	write (2, "OR: ./pipex \"here_doc\" <LIMITER> <cmd> <cmd1> <file>\n", 54);
	exit(EXIT_SUCCESS);
}

int	open_file(char *av, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(av, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open (av, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(av, O_RDONLY, 0777);
	if (file == -1)
		error();
	return (file);
}

int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	buffer = (char *)malloc(4096);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		buffer[i++] = c;
		r = read(0, &c, 1);
	}
	if (c == '\n')
		buffer[i++] = '\n';
	buffer[i] = '\0';
	*line = buffer;
	return (r);
}

void	child_heredoc(int *fd, char *command)
{
	char	**lines;
	int		line_count;

	lines = read_heredoc_input(command, &line_count);
	write_to_pipe(fd, lines, line_count);
}

void	setup_files(char **av, int ac, int *file_out, int *file_in)
{
	*file_out = open_file(av[ac - 1], 1);
	*file_in = open_file(av[1], 2);
	if (*file_out == -1 || *file_in == -1)
		error();
	if (dup2(*file_in, STDIN_FILENO) == -1)
		error();
	close(*file_in);
}
