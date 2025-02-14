/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:21:08 by hfalati           #+#    #+#             */
/*   Updated: 2025/02/11 12:50:16 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**allocate_lines_array(char **lines, int *capacity, int line_count)
{
	char	**new_lines;
	int		i;

	if (line_count >= *capacity)
	{
		new_lines = (char **)malloc(sizeof(char *) * (*capacity * 2));
		if (!new_lines)
			return (NULL);
		i = 0;
		while (i < line_count)
		{
			new_lines[i] = lines[i];
			i++;
		}
		while (i < (*capacity * 2))
		{
			new_lines[i] = NULL;
			i++;
		}
		free(lines);
		*capacity *= 2;
		return (new_lines);
	}
	return (lines);
}

char	**initialize_heredoc(int *line_count)
{
	char	**lines;
	int		capacity;

	capacity = 10;
	lines = malloc(sizeof(char *) * capacity);
	if (!lines)
		return (NULL);
	*line_count = 0;
	return (lines);
}

char	**process_heredoc_input(char **lines, char *delimiter, int *line_count)
{
	char	*line;
	int		capacity;

	capacity = 5;
	while (1)
	{
		write(STDIN_FILENO, "> ", 2);
		if (get_next_line(&line) <= 0)
			break ;
		if (ft_strncmp(line, delimiter, ft_strlen(line) - 1) == 0)
		{
			free(line);
			break ;
		}
		lines = allocate_lines_array(lines, &capacity, *line_count);
		if (!lines)
			break ;
		lines[*line_count] = ft_strdup(line);
		(*line_count)++;
		free(line);
	}
	return (lines);
}

char	**read_heredoc_input(char *delimiter, int *line_count)
{
	char	**lines;

	lines = initialize_heredoc(line_count);
	if (!lines)
		return (NULL);
	return (process_heredoc_input(lines, delimiter, line_count));
}

void	write_to_pipe(int *fd, char **lines, int line_count)
{
	int	i;
	int	len;

	i = 0;
	len = line_count;
	close(fd[0]);
	while (i < len)
	{
		write(fd[1], lines[i], ft_strlen(lines[i]));
		free(lines[i]);
		i++;
	}
	free(lines);
	close(fd[1]);
	exit(EXIT_SUCCESS);
}
