#include "pipex.h"
#include "libft/libft.h"

void	execute(char *av, char **envp)
{
    int i;
    char **command;
    char *path;

    command = ft_split(av, ' ');
    if (!command)
        error();
    path = find_path(command[0], envp);
    if (!path)
    {
        i = 0;
        while (command[i])
            free(command[i++]);
        free(command);
        write(2, "Error: Command not found\n", 25);
        exit(127);
    }
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

char	*find_path(char *command, char **envp)
{
    int i;
    char *path;
    char *path_part;
    char **paths;

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
        {
            i = -1;
            while(paths[++i])
                free(paths[i]);
            free(paths);
            return (path);
        }
        free (path);
        i++;
    }
    i = -1;
    while (paths[++i])
        free(paths[i]);
    free(paths);
    return (0);
}

void    error()
{
    perror("Error");
	exit(EXIT_FAILURE);
}