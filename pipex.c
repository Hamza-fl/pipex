#include "pipex.h"
void	parent_process(char **av, char **envp, int *fd);
void	child_process(char **av, char **envp, int *fd);

int	main(int ac, char **av, char **envp)
{
    int fd[2];
    pid_t pid;

    if (ac == 5)
    {
        if (pipe(fd) == -1)
            error();
        pid = fork();
        if (pid == -1)
            error();
        if (pid == 0)
            child_process(av, envp, fd);
        waitpid(pid, NULL, 0);
		parent_process(av, envp, fd);
    }
    else
    {
		write (2, "Error: Bad arguments\n", 21);
		write (2, "Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 42);
	}
    return (0);
}

void	child_process(char **av, char **envp, int *fd)
{
    int file_in;

    file_in = open(av[1], O_RDONLY, 0777);
    if (file_in == -1)
        error();
    dup2(fd[1], STDOUT_FILENO);
    dup2(file_in, STDIN_FILENO);
    close(fd[0]);
    execute(av[2], envp);
}

void	parent_process(char **av, char **envp, int *fd)
{
    int file_out;

    file_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (file_out == -1)
        error();
    dup2(fd[0], STDIN_FILENO);
    dup2(file_out, STDOUT_FILENO);
    close(fd[1]);
    execute(av[3], envp);
}