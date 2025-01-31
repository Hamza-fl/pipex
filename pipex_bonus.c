#include "pipex.h"
#include "libft/libft.h"
void	here_doc(char *command, int ac);
void	child_process(char *av, char **envp);

int main (int ac, char **av,char **envp)
{
    int i;
    int file_in;
    int file_out;

    if (ac >= 5)
    {
        if (ft_strncmp(av[1], "here_doc", 8) == 0)
        {
            i = 3;
            file_out = open_file(av[ac - 1], 0);
            here_doc(av[2], ac);
        }
        else
        {
            i = 2;
            file_out = open_file(av[ac - 1], 1);
            file_in = open_file(av[1], 2);
            dup2(file_in, STDIN_FILENO);
        }
        while (i < ac - 2)
            child_process(av[i++], envp);
        dup2(file_out, STDOUT_FILENO);
        execute(av[ac - 2], envp);
    }
    min_error();
}

void	here_doc(char *command, int ac)
{
    pid_t pid;
    int fd[2];
    char *line;

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
        wait(NULL);
    }
}

void	child_process(char *av, char **envp)
{
    pid_t pid;
    int fd[2];

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
        dup2(fd[0],STDIN_FILENO);
        waitpid(pid, NULL, 0);
    }
}