/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:14:54 by hfalati           #+#    #+#             */
/*   Updated: 2025/02/13 12:11:18 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void here_doc(char *command, int ac)
{
    pid_t pid;
    int fd[2];
    
    if (ac < 6)
        min_error();
    if (pipe(fd) == -1)
        error();
        
    pid = fork();
    if (pid == 0)
    {
        child_heredoc(fd, command);
    }
    else
    {
        close(fd[1]);
        if (dup2(fd[0], STDIN_FILENO) == -1)
            error();
        close(fd[0]);
    }
}

void child_process(char *av, char **envp)
{
    pid_t pid;
    
    pid = fork();
    if (pid == -1)
        error();
    
    if (pid == 0)  // Child process
    {
        execute(av, envp);
    }
}

void handle_here_doc(char **av, int ac, char **envp)
{
    int i;
    int file_out;
    pid_t pib;
    int pipe_fd[2];  // Single pipe for the commands
    
    i = 3;
    file_out = open_file(av[ac - 1], 0);
    if (file_out == -1)
        error();
        
    // Create single pipe
    if (pipe(pipe_fd) == -1)
        error();
        
    here_doc(av[2], ac);
    
    while (i < ac - 2)
    {
        pid_t pid = fork();
        if (pid == -1)
            error();
            
        if (pid == 0)  // Child process
        {
            close(pipe_fd[0]);  // Close read end
            if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
            {
                close(pipe_fd[1]);
                error();
            }
            close(pipe_fd[1]);
            execute(av[i], envp);
        }
        i++;
    }
    
    pib = fork();
    if (pib == -1)
    {
        close(file_out);
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        error();
    }
    
    if (pib == 0)  // Last command
    {
        close(pipe_fd[1]);  // Close write end
        
        if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
        {
            close(pipe_fd[0]);
            close(file_out);
            error();
        }
        close(pipe_fd[0]);
        
        if (dup2(file_out, STDOUT_FILENO) == -1)
        {
            close(file_out);
            error();
        }
        close(file_out);
        execute(av[ac - 2], envp);
    }
    
    // Parent process
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    close(file_out);
    
    while (wait(NULL) != -1)
        ;
}

void handle_regular_files(char **av, int ac, char **envp)
{
    int file_out;
    int file_in;
    int i;
    pid_t pib;
    int pipe_fd[2];  // Single pipe for the entire process
    
    i = 2;
    setup_files(av, ac, &file_out, &file_in);
    
    // Create single pipe
    if (pipe(pipe_fd) == -1)
        error();
        
    while (i < ac - 2)
    {
        pid_t pid = fork();
        if (pid == -1)
            error();
            
        if (pid == 0)  // Child process
        {
            close(pipe_fd[0]);  // Close read end
            if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
            {
                close(pipe_fd[1]);
                error();
            }
            close(pipe_fd[1]);
            execute(av[i], envp);
        }
        i++;
    }
    
    pib = fork();
    if (pib == -1)
    {
        close(file_out);
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        error();
    }
    
    if (pib == 0)  // Last command (e.g., cat)
    {
        close(pipe_fd[1]);  // Close write end
        
        // Connect input from pipe
        if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
        {
            close(pipe_fd[0]);
            close(file_out);
            error();
        }
        close(pipe_fd[0]);
        
        // Connect output to file
        if (dup2(file_out, STDOUT_FILENO) == -1)
        {
            close(file_out);
            error();
        }
        close(file_out);
        
        execute(av[ac - 2], envp);
    }
    
    // Parent process
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    close(file_out);
    
    while (wait(NULL) != -1)
        ;
}

int	main(int ac, char **av, char **envp)
{
	if (ac >= 5)
	{
		if (ft_strncmp(av[1], "here_doc", 9) == 0)
			handle_here_doc(av, ac, envp);
		else
			handle_regular_files(av, ac, envp);
		return (0);
	}
	min_error();
	return (1);
}

