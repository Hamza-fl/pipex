/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:46:23 by hfalati           #+#    #+#             */
/*   Updated: 2025/02/02 13:49:47 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>

void	execute(char *av, char **envp);
char	*find_path(char *command, char **envp);
void	error(void);

void	min_error(void);
int		open_file(char *av, int i);
int		get_next_line(char **line);

#endif
