#include "pipex.h"
#include "libft/libft.h"
void	execute(char *av, char **envp)
{
    int i;
    char **command;
    char *path;

    command = ft_split(av, ' ');
    path = find_path(command[0], envp);
    if (!path)
    {
        while (command[++i])
            free(command[i]);
        free(command);
        error();
    }
    if (execve(path, command, envp) == -1)
        error();
}

char	*find_path(char *command, char **envp)
{
    int i;
    char *path;
    char *path_part;
    char **paths;

    i = 0;
    while (ft_strnstr(envp[i], "PATH", 4) == 0)
        i++;
    paths = ft_split(envp[i] + 5, ':');
    i = 0;
    while (paths[i])
    {
        path_part = ft_strjoin(paths[i], "/");
        path = ft_strjoin(path_part, command); 
        free(path_part);
        if (access(path, F_OK) == 0)
            return (path);
        free (path);
        i++;
    }
    i = -1;
    while (paths[++i])
        free(paths);
    free(path);
    return (0);
}

void    error()
{
    perror("Error");
	exit(EXIT_FAILURE);
}