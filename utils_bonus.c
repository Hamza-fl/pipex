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
#include "libft/libft.h"

void	min_error(void)
{
	write (2, "Error: Bad argument\n", 20);
	write (2, "Ex: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 47);
	write (2, "./pipex \"here_doc\" <LIMITER> <cmd> <cmd1> <...> <file>\n", 55);
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
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}
