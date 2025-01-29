#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

void	execute(char *av, char **envp);
char	*find_path(char *command, char **envp);
void    error();

#endif